#include <stdio.h>

static const char *face_names[6] = {
    "front", "back", "left", "right", "top", "bottom"
};

static const int opposite_face[6] = {1, 0, 3, 2, 5, 4};

typedef struct {
    int u;
    int f;
} State;

int cubes[500][6];
int dp[500][6];
State parent[500][6];
State path[500];

int main(void) {
    int N;
    int case_num = 1;

    while (scanf("%d", &N) == 1 && N != 0) {
        int i, f, j, fj;
        int max_len = 0;
        State best_end = {-1, -1};
        int path_count = 0;
        int curr_u, curr_f;

        if (case_num > 1) {
            printf("\n");
        }

        for (i = 0; i < N; ++i) {
            for (j = 0; j < 6; ++j) {
                scanf("%d", &cubes[i][j]);
            }
        }

        for (i = 0; i < N; ++i) {
            for (f = 0; f < 6; ++f) {
                dp[i][f] = 1;
                parent[i][f].u = -1;
                parent[i][f].f = -1;

                for (j = 0; j < i; ++j) {
                    for (fj = 0; fj < 6; ++fj) {
                        int bottom_j = opposite_face[fj];

                        if (cubes[j][bottom_j] == cubes[i][f]) {
                            if (dp[j][fj] + 1 > dp[i][f]) {
                                dp[i][f] = dp[j][fj] + 1;
                                parent[i][f].u = j;
                                parent[i][f].f = fj;
                            }
                        }
                    }
                }

                if (dp[i][f] > max_len) {
                    max_len = dp[i][f];
                    best_end.u = i;
                    best_end.f = f;
                }
            }
        }

        printf("Case #%d\n", case_num++);
        printf("%d\n", max_len);

        curr_u = best_end.u;
        curr_f = best_end.f;

        while (curr_u != -1) {
            path[path_count].u = curr_u;
            path[path_count].f = curr_f;
            path_count++;

            {
                State next_p = parent[curr_u][curr_f];
                curr_u = next_p.u;
                curr_f = next_p.f;
            }
        }

        for (i = path_count - 1; i >= 0; --i) {
            printf("%d %s\n", path[i].u + 1, face_names[path[i].f]);
        }
    }

    return 0;
}