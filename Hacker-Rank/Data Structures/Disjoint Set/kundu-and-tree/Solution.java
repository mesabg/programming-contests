import java.io.*;
import java.util.*;


class Node<T>{
    T data;
    Node<T> parent;
    int rank;
    int elements;
};

class DisjointSet<T>{
    private Map<T, Node<T> > map;

    DisjointSet(){
        this.map = new HashMap<>();
    }

    public void makeSet(T data){
        Node<T> node = new Node<>();
        node.data = data;
        node.parent = node;
        node.rank = 0;
        node.elements = 1;
        this.map.put(data, node);
    }

    public void union(T data1, T data2){
        Node<T> node1 = this.map.get(data1);
        Node<T> node2 = this.map.get(data2);

        Node<T> parent1 = this.findSet(node1);
        Node<T> parent2 = this.findSet(node2);

        if (parent1 == parent2) return;

        if (parent1.rank >= parent2.rank){
            parent1.rank = (parent1.rank == parent2.rank) ? parent1.rank + 1 : parent1.rank;
            parent1.elements += parent2.elements;
            parent2.parent = parent1;
        }else{
            parent2.elements += parent1.elements;
            parent1.parent = parent2;
        }
    }

    public T findSet(T data){
        Node<T> set = this.findSet(this.map.get(data));
        return set == null ? null : (T)set.data;
    }

    public int size(T data){
        Node<T> set = this.findSet(this.map.get(data));
        return set.elements;
    }

    private Node<T> findSet(Node<T> node){
        if (node == null) return null;

        Node<T> parent = node.parent;
        if (parent == node) return parent;
        node.parent = this.findSet(node.parent);
        return node.parent;
    }
};


public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        //-- Variables
        int N;
        int u, v;
        int counter = 0;
        char color;
        DisjointSet<Integer> redSet = new DisjointSet<>();
        DisjointSet<Integer> blackSet = new DisjointSet<>();

        N = scanner.nextInt();
        for (int i=0; i<N-1; i++){
            //-- Read and process each edge
            u = scanner.nextInt();
            v = scanner.nextInt();
            color = scanner.next().charAt(0);

            //-- Create sets just if data is not there
            if ( color == 'r' ){
                if (redSet.findSet(u) == null) redSet.makeSet(u);
                if (redSet.findSet(v) == null) redSet.makeSet(v);
                //-- Make the union
                redSet.union(u, v);
            }else if ( color == 'b' ){
                if (blackSet.findSet(u) == null) blackSet.makeSet(u);
                if (blackSet.findSet(v) == null) blackSet.makeSet(v);
                //-- Make the union
                blackSet.union(u, v);
            }
        }

        //-- Check possible combinations
        for (int i=1; i<=N-2; i++)
            for (int j=i+1; j<=N-1; j++) 
                for (int k=j+1; k<=N; k++)
                    if (redSet.findSet(j) != null && blackSet.findSet(j) == null)
                        counter++;
                    else break;

        System.out.print(counter);

        scanner.close();
    }
}