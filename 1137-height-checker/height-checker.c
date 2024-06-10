int comp(const void* a,const void* b){
    return *(int*)a-*(int*)b;
}
int heightChecker(int* heights, int heightsSize) {
    int* arrcopy=malloc(heightsSize*sizeof(int));
    memcpy(arrcopy,heights,heightsSize*sizeof(int));
    qsort(arrcopy,heightsSize,sizeof(int),comp);
    int ans=0;
    for(int i=0;i<heightsSize;i++){
        if(heights[i]!=arrcopy[i]) ans++;
    }
    return ans;
}