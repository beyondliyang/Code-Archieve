#include <stdio.h>
#include <stdlib.h>
#define swap(a, b)                \
    {                             \
        __typeof(a) __temp = (a); \
        (a) = (b);                \
        (b) = __temp;             \
    }

#define max(a, b) (a) > (b) ? (a) : (b)

typedef struct DisjointSet {
    int *father, *rank;
} DisjointSet;

void init(DisjointSet *s, int size) {
    s->father = (int *)malloc(sizeof(int) * size);
    s->rank = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; ++i) {
        s->father[i] = i;
        s->rank[i] = 1;
    }
    return;
}

int find_set(DisjointSet *s, int node) {
    if (s->father[node] != node) {
        s->father[node] = find_set(s, s->father[node]);
    }
    return s->father[node];
}

int merge(DisjointSet *s, int a, int b) {
    int ancestor1 = find_set(s, a);
    int ancestor2 = find_set(s, b);
    if (ancestor1 == ancestor2) return 0;
    if (s->rank[ancestor1] > s->rank[ancestor2]) {
        swap(ancestor1, ancestor2);
    }
    s->father[ancestor1] = ancestor2;
    s->rank[ancestor2] = max(s->rank[ancestor2], s->rank[ancestor1] + 1);
    return 1;
}

void clear(DisjointSet *s) {
    free(s->father);
    free(s->rank);
    free(s);
}

int main() {
    int n, m;
    DisjointSet *dus = (DisjointSet *)malloc(sizeof(DisjointSet));
    scanf("%d%d", &n, &m);
    init(dus, n + 1);
    int a, b, c;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        switch (a) {
            case 1: {
                merge(dus, b, c);
            } break;
            case 2: {
                if (find_set(dus, b) == find_set(dus, c)) {
                    printf("Yes\n");
                } else {
                    printf("No\n");
                }
            } break;
        }
    }
    clear(dus);
    return 0;
}