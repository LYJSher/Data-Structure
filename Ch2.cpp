// 1
bool del(Sq *L, ElemType *min_value){
	if(L.length == 0)
		return false;
	int min_index = 0;
	min_index = L.data[0];
	for(int i=1; i<L.length; i++){
		if(L.data[i] < L.data[min_index])
			min_index = i;
	}
	min_value = L.data[min_index];
	L.data[min_index] = L.data[L.length-1];
	L.length--;
	return true;
}

// 2
void reverse(Sq *L){
	ElemType temp;
	for(int i=0; i<=L.length/2; i++){
		temp = L[i];
		L[i] = L[L.length-1-i];
		L[L.length-1-i] = temp; 
	}
}