#define _USE_MATH_DEFINES  

#include "SI_Method_class.h"
#include <math.h>


double SI_Method::Uxy(double x, double y)
{
	return sin(M_PI * x * y);
}
double SI_Method::f(double x, double y)
{
	return M_PI * M_PI * sin(M_PI * x * y) * (x * x + y * y);
}
double SI_Method::M1(double y)
{
	return sin(M_PI * y);
}
double SI_Method::M2(double y)
{
	return sin(M_PI * 2 * y);
}
double SI_Method::M3(double x)
{
	return sin(M_PI * x * 2);
}
double SI_Method::M4(double x)
{
	return sin(M_PI * x * 3);
}
double SI_Method::M5(double x)
{
	return sin(M_PI * x * 2.5);
}
double SI_Method::M6(double y)
{
	return sin(M_PI * y * 1.5);
}

double** SI_Method::MemoryAllocator(int n, int m)
{
	double** Matrix = NULL;

	Matrix = new double* [n+1];
	for (int i = 0; i < n; i++)
		Matrix[i] = new double[m+1];

	return Matrix;
}
void SI_Method::MemoryCleaner(double** arr, int n)
{
	for (int i = 0; i < n; i++)
		delete[] arr[i];

	delete[] arr;
	arr = NULL;
}

void SI_Method::ShowSolution(double** V)
{
	for (int j = m; j >= 0; j--)
	{
		for (int i = 0; i <= n; i++)
			if ((i > n / 2) && (j > m / 2))
				printf("%10s","-");
			else printf("%10f", V[i][j]);
		printf("\n");
	}
}

double SI_Method::Сalculate_tau() {
	double eig_val_max;
	double eig_val_min;
	double tau;
	double x_step = (b - a) / n;
	double y_step = (d - c) / m;
	
	eig_val_min = (4.0 / (x_step * x_step))
		* sin(M_PI / (2 * n))
		* sin(M_PI / (2 * n))
		+ (4.0 / (y_step * y_step))
		* sin(M_PI / (2 * m))
		* sin(M_PI / (2 * m));

	eig_val_max = (4.0 / (x_step * x_step))
		* sin((M_PI * (n - 1)) / (2 * n))
		* sin((M_PI * (n - 1)) / (2 * n))
		+ (4.0 / (y_step * y_step))
		* sin((M_PI * (m - 1)) / (2 * m))
		* sin((M_PI * (m - 1)) / (2 * m));



	return tau = 2 / (eig_val_max + eig_val_min);
	
	/* вычисление с помощью оценок
	double estim_eig_max;
	double estim_eig_min;
	double tau;

	double h2 = ((n / (b - a)) * (n / (b - a)));
	double k2 = ((m / (d - c)) * (m / (d - c)));
	double a2 = 2 * (h2 + k2);
	
	if ((n == 4) && (m == 4)) {
		estim_eig_min = a2 - h2 - k2;
		estim_eig_max = a2 + h2 + k2;
	}
	else {
		estim_eig_min = 0.000001;
		estim_eig_max = a2 + 2 * h2 + 2 * k2;
	}

	return tau = 2 / (estim_eig_min + estim_eig_max);*/
}

void SI_Method::FillRightSide()
{

	for (int j = 1; j < m; j++)
		for (int i = 1; i < n; i++)
		{
			double Xi, Yj;
			Xi = a + i * ((b - a) / n);
			Yj = c + j * ((d - c) / m);
			F_right_side[i][j] = -f(Xi, Yj);
		}
}

void SI_Method::FillStartSolution()
{
	double h, k;
	h = (b - a) / n;
	k = (d - c) / m;

	for (int j = 0; j <= m; j++)
		for (int i = 0; i <= n; i++)
		{
			if (i == 0 || j == 0 || ((i == n)&&(j <= m / 2)) || ((j == m) && (i <= n / 2)) || ((j == m / 2) && (i >= n / 2)) || ((i == n / 2) && (j >= m / 2)))
			{
				double Xi, Yj;
				Xi = a + i * h;
				Yj = c + j * k;
				if (j == 0) {
					V_old[i][j] = M3(Xi);
					V_new[i][j] = M3(Xi);
				}
				else
					if ((j == m) && (i <= n / 2)) {
						V_old[i][j] = M4(Xi);
						V_new[i][j] = M4(Xi);
					}
					else
						if ((j == m / 2) && (i >= n / 2)) {
							V_old[i][j] = M5(Xi);
							V_new[i][j] = M5(Xi);
						}
				if (i == 0) {
					V_old[i][j] = M1(Yj);
					V_new[i][j] = M1(Yj);
				}
				else
					if ((i == n) && (j <= m / 2)) {
						V_old[i][j] = M2(Yj);
						V_new[i][j] = M2(Yj);
					}
					else
						if ((i == n / 2) && (j >= m / 2)) {
							V_old[i][j] = M6(Yj);
							V_new[i][j] = M6(Yj);
						}
			}
			else{
				V_old[i][j] = 0;
				V_new[i][j] = 0;
			}
		}
}

void SI_Method::ZeidelsMethod()
{
	double	epsCur = 0;			
	double	a2, k2, h2, tau;				

	h2 = (n / (b - a)) * (n / (b - a));
	k2 = (m / (d - c)) * (m / (d - c));
	a2 = -2 * (h2 + k2);
	tau = Сalculate_tau();

	while (true)
	{
		epsMax_achieved = 0;
		for (int j = 1; j < m/2; j++)
			for (int i = 1; i < n; i++)
			{
				double Xi, Yj;
				Xi = a + i * ((b - a) / n);
				Yj = c + j * ((d - c) / m);

				V_new[i][j] = tau * (a2 * V_old[i][j] + h2 * (V_old[i - 1][j] + V_old[i + 1][j]) + k2 * (V_old[i][j - 1] + V_old[i][j + 1]) - F_right_side[i][j]);
				V_new[i][j] += V_old[i][j];

				epsCur = abs(V_new[i][j] - V_old[i][j]);
				if (epsCur > epsMax_achieved)
					epsMax_achieved = epsCur;
			}
		
		for (int j = m/2; j < m ; j++)
			for (int i = 1; i < n/2; i++)
			{
				double Xi, Yj;
				Xi = a + i * ((b - a) / n);
				Yj = c + j * ((d - c) / m);

				V_new[i][j] = tau * (a2 * V_old[i][j] + h2 * (V_old[i - 1][j] + V_old[i + 1][j]) + k2 * (V_old[i][j - 1] + V_old[i][j + 1]) - F_right_side[i][j]);
				V_new[i][j] += V_old[i][j];

				epsCur = abs(V_new[i][j] - V_old[i][j]);
				if (epsCur > epsMax_achieved)
					epsMax_achieved = epsCur;
			}

		iters++;

		if ((epsMax_achieved < eps_initial) || (iters >= Max_iters))
			break;	
		
		//меняем местами указатели для следующей итерации
		double** Temp;
		Temp = V_old;
		V_old = V_new;
		V_new = Temp;

	}
}

//Невязка решения
double SI_Method::DiscrepancyOfSolution()
{
	double	a2, k2, h2;			//Ненулевые элементы матрицы
	double rsEuclid = 0;		//Невязка, посчитанная по евклидовой норме

	h2 = ((n / (b - a)) * (n / (b - a)));
	k2 = ((m / (d - c)) * (m / (d - c)));
	a2 = -2 * (h2 + k2);

	//-AV_s=-F
	//r_s=-AV_s+F F[i][j] = -f(Xi, Yj);
	for (int j = 1; j < m/2; j++)
	{
		for (int i = 1; i < n; i++)
		{
			double Ax, r;
			Ax = -a2 * V_new[i][j] - h2 * (V_new[i - 1][j] + V_new[i + 1][j]) - k2 * (V_new[i][j - 1] + V_new[i][j + 1]);
			r = abs(Ax + F_right_side[i][j]);
			rsEuclid += r * r;
		}
	}
	for (int j = m/2; j < m; j++)
	{
		for (int i = 1; i < n/2; i++)
		{
			double Ax, r;
			Ax = -a2 * V_new[i][j] - h2 * (V_new[i - 1][j] + V_new[i + 1][j]) - k2 * (V_new[i][j - 1] + V_new[i][j + 1]);
			r = abs(Ax + F_right_side[i][j]);
			rsEuclid += r * r;
		}
	}

	return sqrt(rsEuclid);
}

//Проверка вычислительной погрешности
double SI_Method::CheckNumSolution()
{
	
	double h, k;
	double z_max = 0;

	h = (b - a) / n;
	k = (d - c) / m;

	Fill_exact_solution();

	//Погрешность решения
	for (int j = 1; j < m/2; j++)
		for (int i = 1; i < n; i++)
		{
			double z_curr = abs(U_exact[i][j] - V_new[i][j]);

			if (z_curr > z_max)
				z_max = z_curr;
		}
	for (int j = m/2; j < m; j++)
		for (int i = 1; i < n/2; i++)
		{
			double z_curr = abs(U_exact[i][j] - V_new[i][j]);

			if (z_curr > z_max)
				z_max = z_curr;
		}

	return z_max;
}

void SI_Method::Fill_exact_solution() {

	double h, k;
	
	h = (b - a) / n;
	k = (d - c) / m;

	for (int j = 0; j <= m; j++)
		for (int i = 0; i <= n; i++)
		{
			double Xi, Yj;
			Xi = a + i * h;
			Yj = c + j * k;

			if ((j > m / 2) && (i > n / 2))
				U_exact[i][j] = 0;
			else U_exact[i][j] = Uxy(Xi, Yj);
		}
}