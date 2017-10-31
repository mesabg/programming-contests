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
        int g0, b0, size;
        DisjointSet<Integer> disjointSet = new DisjointSet<>();
        ArrayList<Integer> nodes = new ArrayList<Integer>();
        int smallestComponent = Integer.MAX_VALUE;
        int largestComponent = 0;

        N = scanner.nextInt();
        for (int i=0; i<N; i++){
            //-- Read and process each case
            g0 = scanner.nextInt();
            b0 = scanner.nextInt();

            //-- Create sets just if data is not there
            if (disjointSet.findSet(g0) == null) disjointSet.makeSet(g0);
            if (disjointSet.findSet(b0) == null) disjointSet.makeSet(b0);

            //-- Make the union
            disjointSet.union(g0, b0);
            nodes.add(g0);
            nodes.add(b0);
        }

        for (Integer node : nodes){
            size = disjointSet.size(node);
            //-- Update values
            //-- Single nodes are not considered, so size > 1
            smallestComponent = size < smallestComponent && size > 1 ? size : smallestComponent;
            largestComponent = size > largestComponent && size > 1 ? size : largestComponent;
        }

        smallestComponent = smallestComponent == Integer.MAX_VALUE ? 0 : smallestComponent;
        largestComponent = largestComponent == Integer.MAX_VALUE ? 0 : largestComponent;

        System.out.print(smallestComponent);
        System.out.print(" ");
        System.out.print(largestComponent);

        scanner.close();
    }
}