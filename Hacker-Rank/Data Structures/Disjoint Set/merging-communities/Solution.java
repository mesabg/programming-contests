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
        return (T)set.data;
    }

    public int size(T data){
        Node<T> set = this.findSet(this.map.get(data));
        return set.elements;
    }

    private Node<T> findSet(Node<T> node){
        Node<T> parent = node.parent;
        if (parent == node)
            return parent;
        node.parent = this.findSet(node.parent);
        return node.parent;
    }
};


public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N, Q;
        char option;
        int query, personA, personB;

        //-- Main input
        N = scanner.nextInt();
        Q = scanner.nextInt();

        //-- Create DisjointSet
        DisjointSet<Integer> disjointSet = new DisjointSet<>();
        for(int i=1; i<=N; i++)
            disjointSet.makeSet(i);

        //-- Read the queries
        for(int i=0; i<Q; i++){
            option = scanner.next().charAt(0);

            if (option == 'Q'){
                //-- Query statement
                query = scanner.nextInt();
                System.out.println(disjointSet.size(query));

            }else if (option == 'M'){
                //-- Merging statement
                personA = scanner.nextInt();
                personB = scanner.nextInt();
                disjointSet.union(personA, personB);
            }
        }

        scanner.close();
    }
}