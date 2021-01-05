package DataStructuresAndAlgorithm;

public class SegmentTree {

    public static void main(String[] args)
    {
        int[] arr = {1,3,5,7,9,11};

        int n = arr.length;

        int[] st = new int[4 * n];

        _build(arr,st,0,n-1,0);

        for(int i = 0 ; i < st.length ; i++)
        {
            System.out.print(st[i] + " ");
        }

    }

    private static void _build(int[] arr, int[] st, int ss, int ee, int np) {

        if(ss == ee)
        {
            st[np] = arr[ss];
            return;
        }

        int mid = ss + (ee - ss) / 2;

        _build(arr,st,ss,mid,2*np+1);
        _build(arr, st, mid+1, ee, 2*np+2);

        st[np] = st[2 * np + 1] + st[2 * np + 2];

        return;
    }
    
}
