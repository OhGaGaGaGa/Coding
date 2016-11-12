struct Hash_map
{
    static const int mask=0x7fffff;
    int p[mask+1],q[mask+1];
    void clear()
    {
        memset(q,0,sizeof(q));
    }
    int& operator [](int k)
    {
        int i;
        for(i=k&mask;q[i]&&p[i]!=k;i=(i+1)&mask);//??hash??
        p[i]=k;
        return q[i];
    }
};
