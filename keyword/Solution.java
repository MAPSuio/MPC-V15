import java.util.ArrayList;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;

class Solution {

    private class Edge{
        Node origin, destination;
        int cost;

        public Edge (Node origin, Node destination, int cost){
            this.origin = origin;
            this.destination = destination;
            this.cost = cost;
        }

    }

    private class Node implements Comparable<Node>{
        int id, distance, lastEdgeCost;
        Node previous;
        boolean known;
        ArrayList<Edge> edges;

        public Node(int id){
            this.id = id;
            this.distance = Integer.MAX_VALUE;
            this.known = false;
            this.edges = new ArrayList<Edge>();
        }

        public int compareTo(Node other){
            return this.distance - other.distance;
        }
    }

    private void path(Node destination){

        Node current = destination;
        LinkedList<Character> chars = new LinkedList<Character>();

        while(current.previous != null){
            char a = (char) (current.lastEdgeCost % 128);
            chars.add(new Character(a));
            current = current.previous;
        }

        while(chars.size() != 0)
            System.out.print(chars.pop());

        System.out.println();
    }

    public void findPath(Node nodes[], LinkedList<Edge> edges, Node origin, Node destination){

        /* This method assumes that the Nodes are initialized with distance set to Integer.MAX_VALUE,
         * known set to 'false', previous set to null, and edges set to the set of edges in which
         * the node is the origin */

        Node current, currentNeighbour;
        PriorityQueue<Node> queue = new PriorityQueue<Node>();

        queue.add(origin);

        while(queue.size() != 0){

            current = queue.poll();

            for(Edge e: current.edges){
                currentNeighbour = e.destination;

                if(currentNeighbour.known)
                    continue;

                if(currentNeighbour.distance > current.distance + e.cost){
                    currentNeighbour.distance = current.distance + e.cost;
                    currentNeighbour.lastEdgeCost = e.cost;
                    currentNeighbour.previous = e.origin;
                    queue.add(currentNeighbour);
                }
            }

            current.known = true;
        }

        path(destination);
    }

    public void solve(){

        Scanner scanner = new Scanner(System.in);
        int i, j, N, E, originIndex, destinationIndex, currentCost;

        N = 25;
        originIndex = 0;
        destinationIndex = 24;

        LinkedList<Edge> edges = new LinkedList<Edge>();
        Node nodes[] = new Node[N];

        for(i = 0; i < N; i++){
            nodes[i] = new Node(i);
        }

        nodes[originIndex].distance = 0;


        for(i = 0; i < N; i++)
            for(j = 0; j < N; j++){
                currentCost = scanner.nextInt();
                if(currentCost != -1)
                    edges.add(new Edge(nodes[i], nodes[j], currentCost));
            }

        for(Edge e: edges){
            e.origin.edges.add(e);
        }

        findPath(nodes, edges, nodes[originIndex], nodes[destinationIndex]);
    }

    public static void main(String[] args){
        (new Solution()).solve();
    }
}
