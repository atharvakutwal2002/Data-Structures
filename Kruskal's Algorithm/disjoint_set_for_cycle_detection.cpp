

makeset(i){
  parent[i] = i;
}

find(i){
 while(parent[i]!=i){
    i = parent[i];
 }
 return i;
}

union(x,y){
  a = find(x);
  b = find(y);
  parent[b] = a; 
}