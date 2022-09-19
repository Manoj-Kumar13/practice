void insert(stack<int> &s, int temp){
	if(s.size() == 0 or temp>=s.top()){
		s.push(temp);
		return;
	}

	int top = s.top();
	s.pop();
	insert(s,temp);
	s.push(top);
}

void mySort(stack<int> &s){
	if(s.size() == 1){
		return;
	}

	int temp = s.top();
	s.pop();
	mySort(s);
	insert(s,temp);
}
