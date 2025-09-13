
#include <unistd.h>  
#include <fcntl.h>   
#include <stdlib.h>  
#include <sys/types.h> 

#define BUFSIZE 4096

/* -------------------- utilitárias simples (não usam funções externas) -------------------- */

static size_t ft_strlen(const char *s) {
    size_t i = 0;
    if (!s) return 0;
    while (s[i]) i++;
    return i;
}

static char *ft_strdup(const char *s) {
    size_t len = ft_strlen(s);
    char *p = (char*)malloc(len + 1);
    if (!p) return NULL;
    for (size_t i = 0; i <= len; i++) p[i] = s[i];
    return p;
}

static int ft_strcmp(const char *a, const char *b) {
    size_t i = 0;
    while (a[i] && b[i]) {
        if (a[i] != b[i]) return (unsigned char)a[i] - (unsigned char)b[i];
        i++;
    }
    return (unsigned char)a[i] - (unsigned char)b[i];
}

/* concatena s1 + " " + s2 (tira espaços redundantes). Retorna nova malloc'd string. */
static char *join_with_space(char *a, const char *b) {
    if (!b || !b[0]) return a; // nada a juntar
    if (!a || !a[0]) {
        char *r = ft_strdup(b);
        if (!r) { free(a); return NULL; }
        free(a);
        return r;
    }
    size_t la = ft_strlen(a);
    size_t lb = ft_strlen(b);
    /* um espaço entre os dois */
    char *r = (char*)malloc(la + 1 + lb + 1);
    if (!r) { free(a); return NULL; }
    size_t i = 0;
    for (size_t j = 0; j < la; j++) r[i++] = a[j];
    r[i++] = ' ';
    for (size_t j = 0; j < lb; j++) r[i++] = b[j];
    r[i] = 0;
    free(a);
    return r;
}

/* trim spaces (esquerda e direita). Retorna malloc'd string. */
static char *str_trim(const char *s) {
    if (!s) return NULL;
    size_t i = 0;
    while (s[i] == ' ' || s[i] == '\t') i++;
    size_t j = ft_strlen(s);
    if (j == 0) return ft_strdup("");
    j--;
    while ((s[j] == ' ' || s[j] == '\t') && j > i) j--;
    size_t len = (j >= i) ? (j - i + 1) : 0;
    char *r = (char*)malloc(len + 1);
    if (!r) return NULL;
    for (size_t k = 0; k < len; k++) r[k] = s[i + k];
    r[len] = 0;
    return r;
}

/* normalize numeric key: remove leading zeros, keep "0" if all zeros */
static char *normalize_key(const char *s) {
    if (!s) return NULL;
    size_t i = 0;
    while (s[i] == '0') i++;
    size_t len = ft_strlen(s);
    if (i >= len) return ft_strdup("0");
    return ft_strdup(s + i);
}

/* convert small integer (0..999) to string decimal (malloc'd) */
static char *itoa_small(int x) {
    if (x == 0) return ft_strdup("0");
    char buf[16];
    int pos = 0;
    int n = x;
    /* contar digitos */
    int tmp = n; int digits = 0;
    while (tmp > 0) { tmp /= 10; digits++; }
    buf[digits] = 0;
    for (int i = digits - 1; i >= 0; i--) {
        buf[i] = '0' + (n % 10);
        n /= 10;
    }
    return ft_strdup(buf);
}

/* generate "1" followed by 3*power zeros (e.g., power=1 -> "1000") */
static char *scale_key(int power) {
    if (power == 0) return ft_strdup("1");
    int zeros = power * 3;
    size_t len = 1 + zeros;
    char *r = (char*)malloc(len + 1);
    if (!r) return NULL;
    r[0] = '1';
    for (int i = 0; i < zeros; i++) r[1 + i] = '0';
    r[len] = 0;
    return r;
}

/* -------------------- estrutura para o dicionário -------------------- */
typedef struct s_pair {
    char *key;   // normalized numeric key as string
    char *val;   // value string
    struct s_pair *next;
} t_pair;

/* adiciona par chave/valor. */
static int dict_add(t_pair **head, char *key, char *val) {
    t_pair *n = (t_pair*)malloc(sizeof(t_pair));
    if (!n) return 0;
    n->key = key;
    n->val = val;
    n->next = *head;
    *head = n;
    return 1;
}

/* procura valor por key (compara strings). retorna pointer para string (não malloc) ou NULL. */
static const char *dict_get(t_pair *head, const char *key) {
    for (t_pair *p = head; p; p = p->next) {
        if (ft_strcmp(p->key, key) == 0) return p->val;
    }
    return NULL;
}

/* liberta dicionário */
static void dict_free(t_pair *head) {
    t_pair *p = head;
    while (p) {
        t_pair *n = p->next;
        if (p->key) free(p->key);
        if (p->val) free(p->val);
        free(p);
        p = n;
    }
}

/* -------------------- leitura de ficheiro para string (usa open/read) -------------------- */

static char *read_file_all(const char *path) {
    int fd = open(path, O_RDONLY);
    if (fd < 0) return NULL;
    char buf[BUFSIZE];
    char *acc = NULL;
    size_t acc_len = 0;
    ssize_t r;
    while ((r = read(fd, buf, BUFSIZE)) > 0) {
        char *newbuf = (char*)malloc(acc_len + r + 1);
        if (!newbuf) { free(acc); close(fd); return NULL; }
        for (size_t i = 0; i < acc_len; i++) newbuf[i] = acc[i];
        for (ssize_t i = 0; i < r; i++) newbuf[acc_len + i] = buf[i];
        newbuf[acc_len + r] = 0;
        free(acc);
        acc = newbuf;
        acc_len += r;
    }
    close(fd);
    if (r < 0) { free(acc); return NULL; }
    if (!acc) acc = ft_strdup("");
    return acc;
}

/* -------------------- parse do dicionário -------------------- 
   regras: cada linha: [number][spaces]:[spaces][value]\n
*/
static int parse_dict(const char *text, t_pair **out_head) {
    size_t i = 0;
    size_t len = ft_strlen(text);
    while (i < len) {
        /* read line */
        size_t start = i;
        while (i < len && text[i] != '\n') i++;
        size_t end = i; /* [start, end) é a linha */
        /* avançar i (pular \n) */
        if (i < len && text[i] == '\n') i++;
        /* ignore empty lines */
        size_t j = start;
        while (j < end && (text[j] == ' ' || text[j] == '\t')) j++;
        if (j >= end) continue;
        /* procurar ':' */
        size_t colon = start;
        int found = 0;
        while (colon < end) {
            if (text[colon] == ':') { found = 1; break; }
            colon++;
        }
        if (!found) return 0; /* Dict Error */
        /* chave é [start .. colon-1], valor é [colon+1 .. end-1] */
        size_t k1 = start;
        while (k1 < colon && (text[k1] == ' ' || text[k1] == '\t')) k1++;
        size_t k2 = colon;
        while (k2 > k1 && (text[k2 - 1] == ' ' || text[k2 - 1] == '\t')) k2--;
        size_t v1 = colon + 1;
        while (v1 < end && (text[v1] == ' ' || text[v1] == '\t')) v1++;
        size_t v2 = end;
        while (v2 > v1 && (text[v2 - 1] == ' ' || text[v2 - 1] == '\t')) v2--;
        if (k2 <= k1) return 0;
        if (v2 <= v1) return 0;
        /* extrair substrings */
        size_t klen = k2 - k1;
        char *kraw = (char*)malloc(klen + 1);
        if (!kraw) return 0;
        for (size_t t = 0; t < klen; t++) kraw[t] = text[k1 + t];
        kraw[klen] = 0;
        char *vraw = (char*)malloc(v2 - v1 + 1);
        if (!vraw) { free(kraw); return 0; }
        for (size_t t = 0; t < (v2 - v1); t++) vraw[t] = text[v1 + t];
        vraw[v2 - v1] = 0;
        /* trim (já removemos espaços exteriores, mas ainda normalizamos) */
        char *ktrim = str_trim(kraw);
        char *vtrim = str_trim(vraw);
        free(kraw); free(vraw);
        if (!ktrim || !vtrim) { free(ktrim); free(vtrim); return 0; }
        /* validar chave: deve ser apenas dígitos possivelmente com + ? 
           enunciado: "numbers must be treated same as atoi" - aqui aceitamos apenas dígitos */
        size_t p = 0;
        if (ktrim[0] == '+') p = 1;
        int alldig = 1;
        while (ktrim[p]) { if (ktrim[p] < '0' || ktrim[p] > '9') { alldig = 0; break; } p++; }
        if (!alldig) { free(ktrim); free(vtrim); return 0; }
        /* normalize key (remove leading zeros) */
        char *knorm = normalize_key(ktrim);
        free(ktrim);
        if (!knorm) { free(vtrim); return 0; }
        /* adicionar ao dict */
        if (!dict_add(out_head, knorm, vtrim)) { free(knorm); free(vtrim); return 0; }
    }
    return 1;
}

/* -------------------- conversão de tripleta (0..999) usando dicionário -------------------- */
/* retorna malloc'd string (pode ser ""), ou NULL em caso de erro (Dict Error) */
static char *convert_triplet(t_pair *dict, int num) {
    char *res = ft_strdup("");
    if (!res) return NULL;
    if (num >= 100) {
        int hundreds = num / 100;
        char *hs = itoa_small(hundreds);
        const char *unitw = dict_get(dict, hs);
        free(hs);
        if (!unitw) { free(res); return NULL; }
        const char *hundw = dict_get(dict, "100");
        if (!hundw) { free(res); return NULL; }
        res = join_with_space(res, unitw);
        res = join_with_space(res, hundw);
        if (!res) return NULL;
        num %= 100;
    }
    if (num >= 20) {
        int tens = (num / 10) * 10;
        char *ts = itoa_small(tens);
        const char *tensw = dict_get(dict, ts);
        free(ts);
        if (!tensw) { free(res); return NULL; }
        res = join_with_space(res, tensw);
        if (!res) return NULL;
        int ones = num % 10;
        if (ones) {
            char *os = itoa_small(ones);
            const char *onesw = dict_get(dict, os);
            free(os);
            if (!onesw) { free(res); return NULL; }
            res = join_with_space(res, onesw);
            if (!res) return NULL;
        }
    } else if (num > 0) {
        char *ss = itoa_small(num);
        const char *sw = dict_get(dict, ss);
        free(ss);
        if (!sw) { free(res); return NULL; }
        res = join_with_space(res, sw);
        if (!res) return NULL;
    }
    /* se res é vazio string -> retorna "" (não NULL) para indicar sem palavras nessa tripleta */
    return res;
}

/* -------------------- função principal que converte número string usando dicionário -------------------- */

static int convert_number_and_print(t_pair *dict, const char *numstr) {
    /* validar: apenas dígitos */
    if (!numstr || !*numstr) { write(1, "Error\n", 6); return 1; }
    size_t len = ft_strlen(numstr);
    for (size_t i = 0; i < len; i++) {
        if (numstr[i] < '0' || numstr[i] > '9') { write(1, "Error\n", 6); return 1; }
    }
    /* remover zeros à esquerda (mas se o número for todo zeros -> "0") */
    size_t pos = 0;
    while (pos < len && numstr[pos] == '0') pos++;
    char *norm;
    if (pos >= len) norm = ft_strdup("0");
    else norm = ft_strdup(numstr + pos);
    if (!norm) { write(1, "Dict Error\n", 11); return 1; }

    /* caso especial zero */
    if (ft_strlen(norm) == 1 && norm[0] == '0') {
        const char *z = dict_get(dict, "0");
        if (!z) { write(1, "Dict Error\n", 11); free(norm); return 1; }
        write(1, z, ft_strlen(z));
        write(1, "\n", 1);
        free(norm);
        return 0;
    }

    /* dividir em tripletas da direita para esquerda */
    int groups = (ft_strlen(norm) + 2) / 3;
    /* processar grupos da esquerda para a direita */
    int offset = (int)ft_strlen(norm) - groups * 3;
    if (offset < 0) offset = 0;
    /* we'll iterate i = 0..groups-1, each group start index = len - (groups-i)*3, but simpler: compute per group from right */
    char *result = ft_strdup("");
    if (!result) { free(norm); write(1, "Dict Error\n", 11); return 1; }
    size_t nlen = ft_strlen(norm);
    for (int g = 0; g < groups; g++) {
        /* compute substring for group g from right: group 0 is rightmost */
        int start = (int)nlen - 3 * (g + 1);
        if (start < 0) start = 0;
        int end = (int)nlen - 3 * g;
        if (end < start) end = start;
        int glen = end - start;
        /* parse triplet numeric value */
        int val = 0;
        for (int k = 0; k < glen; k++) {
            val = val * 10 + (norm[start + k] - '0');
        }
        if (val != 0) {
            /* convert triplet */
            char *trip = convert_triplet(dict, val);
            if (!trip) { free(result); free(norm); write(1, "Dict Error\n", 11); return 1; }
            if (ft_strlen(trip) > 0) {
                /* group scale key if g>0 */
                if (g > 0) {
                    char *scalek = scale_key(g);
                    const char *scalestr = dict_get(dict, scalek);
                    free(scalek);
                    if (!scalestr) { free(trip); free(result); free(norm); write(1, "Dict Error\n", 11); return 1; }
                    trip = join_with_space(trip, scalestr);
                    if (!trip) { free(result); free(norm); write(1, "Dict Error\n", 11); return 1; }
                }
                /* prepend this group before current result (we are going from right to left) */
                if (ft_strlen(result) == 0) {
                    free(result);
                    result = trip; /* already malloc'd */
                } else {
                    /* we need result = trip + " " + result */
                    size_t rlen = ft_strlen(result);
                    size_t tlen = ft_strlen(trip);
                    char *newr = (char*)malloc(tlen + 1 + rlen + 1);
                    if (!newr) { free(trip); free(result); free(norm); write(1, "Dict Error\n", 11); return 1; }
                    size_t p = 0;
                    for (size_t q = 0; q < tlen; q++) newr[p++] = trip[q];
                    newr[p++] = ' ';
                    for (size_t q = 0; q < rlen; q++) newr[p++] = result[q];
                    newr[p] = 0;
                    free(trip);
                    free(result);
                    result = newr;
                }
            } else {
                free(trip);
            }
        }
    }
    /* tudo pronto - imprimir */
    write(1, result, ft_strlen(result));
    write(1, "\n", 1);
    free(result);
    free(norm);
    return 0;
}

/* -------------------- main -------------------- */

int main(int argc, char **argv) {
    /* Argument parsing */
    const char *dict_path = "numbers.dict"; /* ficheiro padrão do projecto (coloca no mesmo diretório) */
    const char *numarg = NULL;
    if (argc == 2) {
        numarg = argv[1];
    } else if (argc == 3) {
        dict_path = argv[1];
        numarg = argv[2];
    } else {
        /* argumentos inválidos (segundo enunciado: pode receber até 2 argumentos) -> Error */
        write(1, "Error\n", 6);
        return 1;
    }

    /* ler e parse do dicionário */
    char *text = read_file_all(dict_path);
    if (!text) { write(1, "Dict Error\n", 11); return 1; }
    t_pair *dict = NULL;
    if (!parse_dict(text, &dict)) { free(text); dict_free(dict); write(1, "Dict Error\n", 11); return 1; }
    free(text);

    /* converter número e imprimir */
    int rc = convert_number_and_print(dict, numarg);

    dict_free(dict);
    return rc;
}
