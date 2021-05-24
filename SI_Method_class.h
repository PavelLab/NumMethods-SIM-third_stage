#include <iomanip>
#include <iostream>
//#include <fstream>

#pragma once
class SI_Method {
public:
	double** V_new = NULL;
	int		iters = 0;					//������� ��������
	double	epsMax_achieved = 0;		//����������� �������� ������ |x^(s)-x^(s-1)|
	
//protected:
	double const a=1, b=2, c=2, d=3;	//������� ������� ����������� ���������
	int		Max_iters;				//������������ ����� ��������
	double	eps_initial;		//�������� ��������� ��������
	int		n, m;				//����������� �����
	double** V_old = NULL;		//������� ������� 
	double** F_right_side = NULL;	//-f(x, y) �� ������������������ ��������� � ����� �����
	double** U_exact = NULL;		//U - ������ ������� � ����� �����

	SI_Method(int _n, int _m, int _Max_iters, double _eps_initial) {
		n = _n; m = _m;
		Max_iters = _Max_iters; eps_initial = _eps_initial;
		
		V_old = MemoryAllocator(n + 1, m + 1);
		V_new = MemoryAllocator(n + 1, m + 1);
		F_right_side = MemoryAllocator(n + 1, m + 1);
		U_exact= MemoryAllocator(n + 1, m + 1);
	}
	~SI_Method(){
		MemoryCleaner(V_new, n);
		MemoryCleaner(V_old, n);
		MemoryCleaner(F_right_side, n);
		MemoryCleaner(U_exact, n);
	}
	
	double Uxy(double x, double y);
	double f(double x, double y);
	double M1(double y);
	double M2(double y);
	double M3(double x);
	double M4(double x);
	double M5(double x);
	double M6(double y);
	
	double** MemoryAllocator(int n, int m);
	void MemoryCleaner(double** arr, int n);
	
	void Fill_exact_solution();
	void FillRightSide();
	void FillStartSolution();
	
	void ZeidelsMethod();
	double �alculate_tau();
	
	void Solve_SI_Method() {
		FillRightSide();
		FillStartSolution();
		ZeidelsMethod();
	}

	//������� �������
	double DiscrepancyOfSolution();
	
	//�������� �������������� �����������
	double CheckNumSolution();
	
	void ShowSolution(double** Solution);
	void Info() {
		std::cout << "����������� ��������: " << �alculate_tau() << std::endl;
		std::cout << "����������� �����: (" << n << ", " << m << ")" << std::endl;
		std::cout << "������� ����������� X: [" << a << "; " << b << "] " << "������� ����������� Y: [" << c << "; " << d << "]" << std::endl;
		std::cout << "��� ����� �� ��� Ox: h = " << (b - a) / n << std::endl;
		std::cout << "��� ����� �� ��� Oy: k = " << (d - c) / m << std::endl;
		std::cout << "�������� ��������: " << eps_initial << std::endl;
		std::cout << "������� �������: " << DiscrepancyOfSolution() << std::endl;
		std::cout << "��������� ��������: " << iters << std::endl;
		std::cout << "����������� �������� ������: " << std::fixed << std::setprecision(10) << std::scientific << epsMax_achieved << std::endl;
		std::cout << "����������� �������: " << std::fixed << std::setprecision(10) << std::scientific << CheckNumSolution() << std::endl;
	}
};