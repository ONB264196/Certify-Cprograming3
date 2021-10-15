#include"stdio.h"
#define _16c

#ifdef _40Q6
#define MONEYS 6
int main(void) 
{
	int yen[MONEYS] = { 500,100,50,10,5,1 };
	int left[MONEYS], back[MONEYS];
	int i, amount, number;
	int price, payment, change;

	//各硬貨の残枚数と釣銭枚数の初期化
	for (i = 0; i < MONEYS; i++) {
		left[i] = 0;
		back[i] = 0;
	}
	
	//現在の硬貨の残枚数の入力
	do 
	{
		printf("額面（円）：　");
		scanf_s("%d", &amount);
		printf("残枚数:　");
		scanf_s("%d", &number);
		for (i = 0; i < MONEYS; i++) {
			if (yen[i] == amount) {
				left[i] = number;
				break;
			}
		}
	} while (amount != -1);

	//購入金額の入力
	printf("\n 購入金額（円）：　");
	scanf_s("%d", &price);
	
	//支払金額の入力
	printf("支払金額（円）：　");
	scanf_s("%d", &payment);

	change = payment - price;
	if (change < 0) {
		printf("\n 支払金額不足\n");
	}
	else {
		printf("\n 釣銭 %5d 円（内訳）\n", change);
		for (i = 0; i < MONEYS; i++) {
			while (change > 0 && left[i] > 0 && change >= yen[i]) {
				left[i]--;
				back[i]++;
				change -= yen[i];
			}
			if (change == 0) {
				break;
			}
		}
		if (change != 0) {
			printf("釣銭不足\n");
		}
		else {
			for (i = 0; i < MONEYS; i++) {
				printf("%4d 円 : %3d 枚\n", yen[i], back[i]);
			}
		}
	}
	return 0;
}
#endif


#ifdef _40Q6a
#define MONEYS 7
int main(void)
{
	int yen[] = { 1000,500,100,50,10,5,1 };
	int left[MONEYS], back[MONEYS];
	int i, amount, number;
	int num, price, payment, change, shortage;
	int total = 0;

	//各硬貨の残枚数と釣銭枚数の初期化
	for (i = 0; i < MONEYS; i++) {
		left[i] = 0;
		back[i] = 0;
	}

	//現在の硬貨所持数の入力
	do
	{
		printf("額面（円）：　");
		scanf_s("%d", &amount);
		printf("残枚数:　");
		scanf_s("%d", &number);
		for (i = 0; i < MONEYS; i++) {
			if (yen[i] == amount) {
				left[i] = number;
				break;
			}
		}
	} while (amount != -1);

	//購入金額の入力
	printf("\n ねだん（円）：　");
	scanf_s("%d", &price);

	//支払枚数の入力
	printf("%4d円 : ", 1000);
	scanf_s("%d", &num);
	total += (1000 * num);
	printf("%4d円 : ", 500);
	scanf_s("%d", &num);
	total += (500 * num);
	printf("%4d円 : ", 100);
	scanf_s("%d", &num);
	total += (100 * num);
	printf("%4d円 : ", 50);
	scanf_s("%d", &num);
	total += (50 * num);
	printf("%4d円 : ", 10);
	scanf_s("%d", &num);
	total += (10 * num);
	printf("%4d円 : ", 5);
	scanf_s("%d", &num);
	total += (5 * num);
	printf("%4d円 : ", 1);
	scanf_s("%d", &num);
	total += (1 * num);

	payment = total;
	printf("はらう　：　%4d（円）", payment);
	change = payment - price;
	if (change < 0) {
		shortage = change;
		printf("\n %4d（円）たりない\n", shortage);
	}
	else {
		printf("\n おつり %5d 円　\n", change);
		for (i = 0; i < MONEYS; i++) {
			while (change > 0 && left[i] > 0 && change >= yen[i]) {
				left[i]--;
				back[i]++;
				change -= yen[i];
			}
			if (change == 0) {
				break;
			}
		}
		for (i = 0; i < MONEYS; i++) {
			printf("%4d 円 : %3d 枚\n", yen[i], back[i]);
		}
	}

	return 0;
}
#endif


#ifdef _16a
int main(void) {
	int a;

	printf("10進数を入力してください：");
	scanf_s("%d", &a);
	putchar('\n');
	printf("16進数では「%X」です", a);
}
#endif


#ifdef _16b
int main(void) {
	int a, b;
	int x = 0;
	char s[100];

	printf("10進数を入力してください：");
	scanf_s("%d", &a);
	putchar('\n');
	printf("16進数では「");

	for (int i = 99; i >= 0; i--) {
		switch (a % 16) {
		case 0: s[i] = '0'; break;
		case 1: s[i] = '1'; break;
		case 2:	s[i] = '2';	break;
		case 3:	s[i] = '3';	break;
		case 4:	s[i] = '4';	break;
		case 5:	s[i] = '5';	break;
		case 6:	s[i] = '6';	break;
		case 7:	s[i] = '7';	break;
		case 8:	s[i] = '8';	break;
		case 9:	s[i] = '9';	break;
		case 10: s[i] = 'A'; break;
		case 11: s[i] = 'B'; break;
		case 12: s[i] = 'C'; break;
		case 13: s[i] = 'D'; break;
		case 14: s[i] = 'E'; break;
		case 15: s[i] = 'F'; break;
		}
		a /= 16;
	}
	for (int i = 0; i < 100; i++) {
		if (s[i] != '0') {
			b = i;
			break;
		}
	}
	for (int i = b; i < 100; i++) {
		printf("%c", s[i]);
	}
	printf("」です。");
}
#endif


#ifdef _16c
int main(void) {
	int x;
	int A = 0, B = 0, C = 0, D = 0, E = 0, F = 0, G = 0, H = 0, I = 0, J = 0;
	int count = 0;
	printf("10進数を入力してください：");
	scanf_s("%d", &x);
	putchar('\n');
	printf("16進数では「");
	
	while (1) {
		x--;
		J++;
		if (J == 16) {
			J = 0;
			I++;
			if (I == 16) {
				I = 0;
				H++;
				if (H == 16) {
					H = 0;
					G++;
					if (G == 16) {
						G = 0;
						F++;
						if (F == 16) {
							F = 0;
							E++;
							if (E == 16) {
								E = 0;
								D++;
								if (D == 16) {
									D = 0;
									C++;
									if (C == 16) {
										C = 0;
										B++;
										if (B == 16) {
											B = 0;
											A++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if (x == 0) break;
		if (A == 15 && B == 15 && C == 15 && D == 15 && E == 15 &&
			F == 15 && G == 15 && H == 15 && I == 15 && J == 15) break;
	}
	
	//表示
	if (A < 10)printf("%d", A);
	else if (A == 10) putchar('A');
	else if (A == 11) putchar('B');
	else if (A == 12) putchar('C');
	else if (A == 13) putchar('D');
	else if (A == 14) putchar('E');
	else if (A == 15) putchar('F');

	if (B < 10)printf("%d", B);
	else if (B == 10) putchar('A');
	else if (B == 11) putchar('B');
	else if (B == 12) putchar('C');
	else if (B == 13) putchar('D');
	else if (B == 14) putchar('E');
	else if (B == 15) putchar('F');

	if (C < 10)printf("%d", C);
	else if (C == 10) putchar('A');
	else if (C == 11) putchar('B');
	else if (C == 12) putchar('C');
	else if (C == 13) putchar('D');
	else if (C == 14) putchar('E');
	else if (C == 15) putchar('F');

	if (D < 10)printf("%d", D);
	else if (D == 10) putchar('A');
	else if (D == 11) putchar('B');
	else if (D == 12) putchar('C');
	else if (D == 13) putchar('D');
	else if (D == 14) putchar('E');
	else if (D == 15) putchar('F');

	if (E < 10)printf("%d", E);
	else if (E == 10) putchar('A');
	else if (E == 11) putchar('B');
	else if (E == 12) putchar('C');
	else if (E == 13) putchar('D');
	else if (E == 14) putchar('E');
	else if (E == 15) putchar('F');

	if (F < 10)printf("%d", F);
	else if (F == 10) putchar('A');
	else if (F == 11) putchar('B');
	else if (F == 12) putchar('C');
	else if (F == 13) putchar('D');
	else if (F == 14) putchar('E');
	else if (F == 15) putchar('F');

	if (G < 10)printf("%d", G);
	else if (G == 10) putchar('A');
	else if (G == 11) putchar('B');
	else if (G == 12) putchar('C');
	else if (G == 13) putchar('D');
	else if (G == 14) putchar('E');
	else if (G == 15) putchar('F');

	if (H < 10)printf("%d", H);
	else if (H == 10) putchar('A');
	else if (H == 11) putchar('B');
	else if (H == 12) putchar('C');
	else if (H == 13) putchar('D');
	else if (H == 14) putchar('E');
	else if (H == 15) putchar('F');

	if (I < 10)printf("%d", I);
	else if (I == 10) putchar('A');
	else if (I == 11) putchar('B');
	else if (I == 12) putchar('C');
	else if (I == 13) putchar('D');
	else if (I == 14) putchar('E');
	else if (I == 15) putchar('F');

	if (J < 10)printf("%d", J);
	else if (J == 10) putchar('A');
	else if (J == 11) putchar('B');
	else if (J == 12) putchar('C');
	else if (J == 13) putchar('D');
	else if (J == 14) putchar('E');
	else if (J == 15) putchar('F');

	printf("」です。");

	return 0;
}
#endif
