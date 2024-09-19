/* 2352495 –≈16 ’≈÷Ò∫Õ */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	double x, y;
	int a, b, c, d, e, f, g, h, i, j, k, l;
	double n1, n2, n3, n4, n5, n6, n7, n8, n9, n10;
	int m;
	n1 = 1000000000, n2 = 100000000, n3 = 10000000, n4 = 1000000, n5 = 100000, n6 = 10000, n7 = 1000, n8 = 100, n9 = 10, n10 = 1;
	printf("«Î ‰»Î[0-100“⁄)÷Æº‰µƒ ˝◊÷:\n");;
	scanf("%lf", &x);
	a = (int)(x / n1);
	b = (int)((x - a * n1) / n2);
	c = (int)((x - a * n1 - b * n2) / n3);
	d = (int)((x - a * n1 - b * n2 - c * n3) / n4);
	e = (int)((x - a * n1 - b * n2 - c * n3 - d * n4) / n5);
	f = (int)((x - a * n1 - b * n2 - c * n3 - d * n4 - e * n5) / n6);
	g = (int)((x - a * n1 - b * n2 - c * n3 - d * n4 - e * n5 - f * n6) / n7);
	h = (int)((x - a * n1 - b * n2 - c * n3 - d * n4 - e * n5 - f * n6 - g * n7) / n8);
	i = (int)((x - a * n1 - b * n2 - c * n3 - d * n4 - e * n5 - f * n6 - g * n7 - h * n8) / n9);
	j = (int)((x - a * n1 - b * n2 - c * n3 - d * n4 - e * n5 - f * n6 - g * n7 - h * n8 - i * n9) / n10);

	y = a * n1 + b * n2 + c * n3 + d * n4 + e * n5 + f * n6 + g * n7 + h * n8 + i * n9 + j * n10;
	m = (int)round(100 * (x - y));
	l = m % 10;
	k = (m - l) / 10;

	printf("¥Û–¥Ω·π˚ «:\n");

	// Æ“⁄Œªº∞“⁄Œª ‰≥ˆ
	if (a != 0) {
		switch (a) {
			case 1:
				printf("“º ∞");
				break;
			case 2:
				printf("∑° ∞");
				break;
			case 3:
				printf( "»˛ ∞");
				break;
			case 4:
				printf( "À¡ ∞");
				break;
			case 5:
				printf( "ŒÈ ∞");
				break;
			case 6:
				printf( "¬Ω ∞");
				break;
			case 7:
				printf( "∆‚ ∞");
				break;
			case 8:
				printf( "∞∆ ∞");
				break;
			case 9:
				printf( "æ¡ ∞");
				break;
			default:
				break;
		}
	}
	if (b != 0) {
		switch (b) {
			case 1:
				printf( "“º");
				break;
			case 2:
				printf( "∑°");
				break;
			case 3:
				printf( "»˛");
				break;
			case 4:
				printf( "À¡");
				break;
			case 5:
				printf( "ŒÈ");
				break;
			case 6:
				printf( "¬Ω");
				break;
			case 7:
				printf( "∆‚");
				break;
			case 8:
				printf( "∞∆");
				break;
			case 9:
				printf( "æ¡");
				break;
			default:
				break;
		}
	}
	if (a != 0 || b != 0)
		printf( "“⁄");

	//ÕÚŒª ‰≥ˆ
	if (c != 0) {
		switch (c) {
			case 1:
				printf( "“º«™");
				break;
			case 2:
				printf( "∑°«™");
				break;
			case 3:
				printf( "»˛«™");
				break;
			case 4:
				printf( "À¡«™");
				break;
			case 5:
				printf( "ŒÈ«™");
				break;
			case 6:
				printf( "¬Ω«™");
				break;
			case 7:
				printf( "∆‚«™");
				break;
			case 8:
				printf( "∞∆«™");
				break;
			case 9:
				printf( "æ¡«™");
				break;
			default:
				break;
		}
	}
	if (c == 0 && d != 0 && x >= 10100000)
		printf( "¡„");
	if (d != 0) {
		switch (d) {
			case 1:
				printf( "“º∞€");
				break;
			case 2:
				printf( "∑°∞€");
				break;
			case 3:
				printf( "»˛∞€");
				break;
			case 4:
				printf( "À¡∞€");
				break;
			case 5:
				printf( "ŒÈ∞€");
				break;
			case 6:
				printf( "¬Ω∞€");
				break;
			case 7:
				printf( "∆‚∞€");
				break;
			case 8:
				printf( "∞∆∞€");
				break;
			case 9:
				printf( "æ¡∞€");
				break;
			default:
				break;
		}
	}
	if (d == 0 && e != 0 && x >= 1010000)
		printf( "¡„");
	if (e != 0) {
		switch (e) {
			case 1:
				printf( "“º ∞");
				break;
			case 2:
				printf( "∑° ∞");
				break;
			case 3:
				printf( "»˛ ∞");
				break;
			case 4:
				printf( "À¡ ∞");
				break;
			case 5:
				printf( "ŒÈ ∞");
				break;
			case 6:
				printf( "¬Ω ∞");
				break;
			case 7:
				printf( "∆‚ ∞");
				break;
			case 8:
				printf( "∞∆ ∞");
				break;
			case 9:
				printf( "æ¡ ∞");
				break;
			default:
				break;
		}
	}
	if (e == 0 && f != 0 && x >= 101000)
		printf( "¡„");
	if (f != 0) {
		switch (f) {
			case 1:
				printf( "“º");
				break;
			case 2:
				printf( "∑°");
				break;
			case 3:
				printf( "»˛");
				break;
			case 4:
				printf( "À¡");
				break;
			case 5:
				printf( "ŒÈ");
				break;
			case 6:
				printf( "¬Ω");
				break;
			case 7:
				printf( "∆‚");
				break;
			case 8:
				printf( "∞∆");
				break;
			case 9:
				printf( "æ¡");
				break;
			default:
				break;
		}
	}
	if (c != 0 || d != 0 || e != 0 || f != 0)
		printf( "ÕÚ");

	//∏ˆŒª ‰≥ˆ
	if (g != 0) {
		switch (g) {
			case 1:
				printf( "“º«™");
				break;
			case 2:
				printf( "∑°«™");
				break;
			case 3:
				printf( "»˛«™");
				break;
			case 4:
				printf( "À¡«™");
				break;
			case 5:
				printf( "ŒÈ«™");
				break;
			case 6:
				printf( "¬Ω«™");
				break;
			case 7:
				printf( "∆‚«™");
				break;
			case 8:
				printf( "∞∆«™");
				break;
			case 9:
				printf( "æ¡«™");
				break;
			default:
				break;
		}
	}
	if (g == 0 && h != 0 && x >= 10100)
		printf( "¡„");
	if (h != 0) {
		switch (h) {
			case 1:
				printf( "“º∞€");
				break;
			case 2:
				printf( "∑°∞€");
				break;
			case 3:
				printf( "»˛∞€");
				break;
			case 4:
				printf( "À¡∞€");
				break;
			case 5:
				printf( "ŒÈ∞€");
				break;
			case 6:
				printf( "¬Ω∞€");
				break;
			case 7:
				printf( "∆‚∞€");
				break;
			case 8:
				printf( "∞∆∞€");
				break;
			case 9:
				printf( "æ¡∞€");
				break;
			default:
				break;
		}
	}
	if (h == 0 && i != 0 && x >= 1010)
		printf( "¡„");
	if (i != 0) {
		switch (i) {
			case 1:
				printf( "“º ∞");
				break;
			case 2:
				printf( "∑° ∞");
				break;
			case 3:
				printf( "»˛ ∞");
				break;
			case 4:
				printf( "À¡ ∞");
				break;
			case 5:
				printf( "ŒÈ ∞");
				break;
			case 6:
				printf( "¬Ω ∞");
				break;
			case 7:
				printf( "∆‚ ∞");
				break;
			case 8:
				printf( "∞∆ ∞");
				break;
			case 9:
				printf( "æ¡ ∞");
				break;
			default:
				break;
		}
	}
	if (i == 0 && j != 0 && x >= 101)
		printf( "¡„");
	if (j != 0) {
		switch (j) {
			case 1:
				printf( "“º");
				break;
			case 2:
				printf( "∑°");
				break;
			case 3:
				printf( "»˛");
				break;
			case 4:
				printf( "À¡");
				break;
			case 5:
				printf( "ŒÈ");
				break;
			case 6:
				printf( "¬Ω");
				break;
			case 7:
				printf( "∆‚");
				break;
			case 8:
				printf( "∞∆");
				break;
			case 9:
				printf( "æ¡");
				break;
			default:
				break;
		}
	}
	if (g != 0 || h != 0 || i != 0 || j != 0)
		printf( "‘≤");

	//¥¶¿Ì–° ˝µ„∫Û¡ΩŒª
	if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0 || g != 0 || h != 0 || i != 0 || j != 0) {
		if (k == 0 && l == 0)
			printf( "’˚\n");
	}
	if (k != 0) {
		switch (k) {
			case 1:
				printf( "“ºΩ«");
				break;
			case 2:
				printf( "∑°Ω«");
				break;
			case 3:
				printf( "»˛Ω«");
				break;
			case 4:
				printf( "À¡Ω«");
				break;
			case 5:
				printf( "ŒÈΩ«");
				break;
			case 6:
				printf( "¬ΩΩ«");
				break;
			case 7:
				printf( "∆‚Ω«");
				break;
			case 8:
				printf( "∞∆Ω«");
				break;
			case 9:
				printf( "æ¡Ω«");
				break;
			default:
				break;
		}
	}

	if (k != 0 && l == 0) {
		printf("’˚");
	}

	if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0 || g != 0 || h != 0 || i != 0 || j != 0) {
		if (k == 0 && l != 0) {
			if (x >= 1.01)
				printf( "¡„");
		}
	}
	if (l != 0) {
		switch (l) {
			case 1:
				printf( "“º∑÷\n");
				break;
			case 2:
				printf( "∑°∑÷\n");
				break;
			case 3:
				printf( "»˛∑÷\n");
				break;
			case 4:
				printf( "À¡∑÷\n");
				break;
			case 5:
				printf( "ŒÈ∑÷\n");
				break;
			case 6:
				printf( "¬Ω∑÷\n");
				break;
			case 7:
				printf( "∆‚∑÷\n");
				break;
			case 8:
				printf( "∞∆∑÷\n");
				break;
			case 9:
				printf( "æ¡∑÷\n");
				break;
			default:
				break;
		}
	}
	if (x == 0)
		printf( "¡„‘≤’˚\n");

	return 0;
}