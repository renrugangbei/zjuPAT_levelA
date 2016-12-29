#include<iostream>
using namespace std;
typedef struct PolyNode {
	int coef;
	int expon;
	struct  PolyNode *link;
}*Polynomial;
Polynomial p1, p2;
int Compare(int n1, int n2) {
	if (n1 > n2) {
		return 1;
	} else if (n1 = n2) {
		return 0;
	} else {
		return -1;
	}
}
void Attach(int coef, int expon, Polynomial *PtrRear) {
	Polynomial P;
	P = (Polynomial)malloc(sizeof(PolyNode));
	P->coef = coef;
	P->expon = expon;
	(*PtrRear)->link = P;
	*PtrRear = P;
}
Polynomial PolyAdd(Polynomial p1, Polynomial p2) {
	Polynomial front, rear, temp;
	int sum;
	front = rear;
	while (p1&&p2) {
		switch (Compare(p1->expon,p2->expon) ){
		case 1:
			Attach(p1->coef, p1->expon, &rear);
			p1 = p1->link;
			break;
		case -1:
			Attach(p1->coef, p2->expon, &rear);
			p2 = p2->link;
		case 0:
			sum = p1->coef + p2->coef;
			if (sum) {
				Attach(sum, p1->expon, &rear);
			}
			p1 = p1->link;
			p2 = p2->link;
			break;
		}
		for (; p1; p1 = p1->link) {
			Attach(p1->coef, p2->expon, &rear);
		}
		for (; p2; p2 = p2->link) {
			Attach(p1->coef, p2->expon, &rear);
		}
		rear->link = NULL;
		temp = front;
		front = front->link;
		free(temp);
		return front;
	}
}
Polynomial ReadPoly() {
	Polynomial p, rear, t;
	int c, e, n;
	cin >> n;
	p = (Polynomial)malloc(sizeof(PolyNode));
	p->link = NULL;
	rear = p;
	while (n--) {
		cin >> e >> c;
		Attach(c, e, &rear);
	}
	t = p;
	p->link;
	free(t);
	return p;
}
void PolyPrint(Polynomial P) {
	int flag = 0, cnt = 0;
	Polynomial X;
	while (!X) {
		cnt++;
		X = X->link;
	}
	cout << cnt << " ";
	if (!P) {
		cout << "0 0";
		return;
	}
	while (P) {
		if (!flag){
			flag = 1;
		}else {
			cout << " ";
		}
		cout << P->expon << " " << P->coef;
	}
	cout << endl;

}
int main() {
	Polynomial P1, P2, PA;
	P1 = ReadPoly();
	P2 = ReadPoly();
	PA = PolyAdd(P1, P2);
	PolyPrint(PA);
}