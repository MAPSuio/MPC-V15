import java.util.Scanner;
import java.util.Stack;

public class martinvl {
    private static int INFINITY = Integer.MAX_VALUE;
    private static int MAX_COST = INFINITY/2;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = 25;
        int[][] costs = new int[n][n];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                costs[i][j] = in.nextInt();

                if (costs[i][j] == -1) {
                    costs[i][j] = MAX_COST;
                }
            }
        }

        int[] prev = dijkstra(costs, 0);
        Stack<Integer> pathCosts = new Stack<Integer>();

        for (int node = 24; node != 0; node = prev[node]) {
            System.out.println(node + " " + costs[prev[node]][node]);
            pathCosts.push(costs[prev[node]][node]);
        }

        int sum = 0;

        while (!pathCosts.isEmpty()) {
            int c = pathCosts.pop();
            sum += c;
            System.out.print((char)(c % 128));
        }
        System.out.println();
        System.out.println(sum);
    }

    // Dense graph in-place path version O(|V|^2)
    public static int[] dijkstra(int[][] costs, int root) {
        int N = costs.length;
        boolean[] completed = new boolean[N];
        int[] prev = new int[N];

        int current = root;
        for (int i = 0; i < N; i++) {
            completed[current] = true;

            int next = -1;
            int currentCost = costs[root][current];
            int lowestCost = INFINITY;

            for (int j = 0; j < N; j++) {
                int stepCost = costs[current][j];
                int newCost = currentCost + stepCost;

                if (newCost < costs[root][j]) {
                    prev[j] = current;
                    costs[root][j] = newCost;
                }

                if (!completed[j] && costs[root][j] < lowestCost) {
                    next = j;
                    lowestCost = costs[root][j];
                }
            }

            current = next;
        }

        return prev;
    }
}
