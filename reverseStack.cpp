void insertBottom(stack<int> &s,int top){
	if(s.size() == 0){
		s.push(top);
		return;
	}

	int temp = s.top();
	s.pop();
	insertBottom(s,top);
	s.push(temp);

}

void reverseStack(stack<int> &s){
	if(s.size() == 2){
		int top1 = s.top();
		s.pop();
		int top2 = s.top();
		s.pop();
		s.push(top1);
		s.push(top2);
		return;
	}

	// if(s.size() == 1){
	// 	return;
	// }

	int top = s.top();
	s.pop();
	reverseStack(s);
	insertBottom(s,top);


}
