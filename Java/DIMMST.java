import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;



public class DIMMST
{

    public static class Edges
    {
        int source;
        int desti;
        long weight;
        
        Edges(int s,int d, long w)
        {
            this.desti = d;
            this.source = s;
            this.weight = w;
        }
    }

    public static void main(String args[]) throws IOException
    {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String nd[] = br.readLine().split(" ");

        int n = Integer.parseInt(nd[0]);
       

        ArrayList <ArrayList <Integer > > list = new ArrayList<>();

        for(int i = 0 ; i < n ; i ++)
        {
            String str[] = br.readLine().split(" ");
            ArrayList <Integer> values = new ArrayList<>();
            for(int k = 0 ; k < str.length ; k ++)
            {
                values.add(Integer.parseInt(str[k]));
            } 
            list.add(values);
        }

        ArrayList <Edges> edges = new ArrayList<>();

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i+1 ; j < n ; j++)
            {
                long weight = diff(list.get(i),list.get(j));
                Edges current = new  Edges(i,j,weight);
                edges.add(current);   
            }
        }

        long graph[][] = new long[n][n];

        for(int i =0; i< edges.size(); i++)
        {
            graph[edges.get(i).source][edges.get(i).desti] = edges.get(i).weight;
            graph[edges.get(i).desti][edges.get(i).source] = edges.get(i).weight;
        }
        
        primMST(graph);
    }

    private static long diff (ArrayList<Integer> x, ArrayList<Integer> y)
    {
        long w = 0;
        for(int i = 0 ; i < x.size() ; i++)
        {
            w += Math.abs(x.get(i) - y.get(i));
        }
        return w;
    }

    static void primMST(long graph[][])
    {
        int v = graph.length;

        int parent[] = new int[v];
        long key[] = new long[v];
        boolean MSTset[] = new boolean[v];

        for(int i = 0 ; i < v ; i++)
        {
            key[i] = Integer.MIN_VALUE;
            MSTset[i] = false;
        }
        key[0] = 0;
        parent[0] = 0;

        for(int count = 0 ; count < v-1 ; count++)
        {
            long u = maxKey(key,MSTset,v);
            MSTset[(int) u] = true;

            for(int j = 0 ; j < v; j++)
            {
                if(graph[(int) u][j] != 0 && MSTset[j] == false && graph[(int) u][j] > key[j])
                {
                    parent[j] = (int) u;
                    key[j] = graph[(int) u][j];
                }
            }
        }

        printMST(parent,graph,v);
    }

    private static void printMST(int[] parent, long[][] graph ,int v)
    {
        long sum = 0;
        for(int i = 0 ; i < v ; i++)
        {
            sum += graph[parent[i]][i];
        }
        System.out.println(sum);
    }

    private static long maxKey(long[] key, boolean[] mst , int v)
    {
        long max = Integer.MIN_VALUE;
        long index = -1;
        for(int i = 0 ; i < v ; i++)
        {
            if(mst[i] == false && key[i] > max)
            {
                max = key[i];
                index = i;
            }
        }
        return index;
    }
}