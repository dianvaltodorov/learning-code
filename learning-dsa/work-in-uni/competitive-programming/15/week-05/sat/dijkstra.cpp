void dijkstra(unsigned s)
{
    unsigned i;
    for(i = 0; i < n; i++)
    {
        d[i] = A[s][i] != 0 ? A[s][i] : MAX_VALUE;
        pred[i] =  A[s][i] != 0 ? s : NO_PARENT;
        T[s] = 0;
    }

   pred[s] = NO_PARENT;
   T[s] = 0;

   while(1)
   {

        unsigned j = NO_PARENT;
        unsigned di = MAX_VALUE;

        /* find the closest path*/
        for(i = 0; i < n; i++)
        {
            if(T[i] && d[i] < di)
            {
                di = d[i];
                j = i;
            }
        }

        // Mark the closest
        if(NO_PARENT) break;
        T[j] = 0;


        //
        for(i = 0; i < n; i++)
            if(T[i] && A[i][i] != ))
                if(d[i] > d[j] + A[j][i])
                {
                    d[i] = d[j] + A[j][i];
                    pred[i] = j;

                }
   }

}
