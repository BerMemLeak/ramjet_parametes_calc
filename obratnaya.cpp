#include <iostream>

class dvig {
private:
//ДАНО
	double M_n = 3.2; // парпметр набегающего потока
	double T_n = 223.3; // парпметр набегающего потока
	
	double T_p = 1950; // термодинамические характеристики продуктов сгорания
	double k = 1.27; // термодинамические характеристики продуктов сгорания
	double R = 282; // термодинамические характеристики продуктов сгорания
	
	double k_b = 1.4; // термодинамические характеристики воздуха
	double R_b = 287;// термодинамические характеристики воздуха
	
	double f_kr = 0.5; // относительные площади сечения тракта ПВРД
	double f_a = 1; // относительные площади сечения тракта ПВРД
	
	double fi_n = 1; // характеристика воздухозаборника 
	double C_x_dop = 0; // характеристика воздухозаборника 
	double n = 16; // соотношение расхода воздуха и топлива
	double C_R = 0.676547 ;// коэфф тяги
	
	double sigma_c = 1;
	
//ИЩЕМ
	double f_vx ; //относительные площади сечения тракта ПВРД
	double betta;
	double kappa;
	double tetta_tetta;
	double C_tetta;
	double lambda_a;
	
	double a_kr;
	double V_n;
	double R_ud;
	double q_lambda;
public:	
	dvig(double M, double T, double Tp, double kk, double RR, double kb, double Rb, 
		double CR, double fkr, double fa, double fin, double Cxdop, double nn) 
	: M_n(M), T_n(T), T_p(Tp), k(kk), R(RR), k_b(kb), R_b(Rb),
	C_R(CR), f_kr(fkr), f_a(fa), fi_n(fin), C_x_dop(Cxdop), n(nn) {}
	
	
	void set_lambda_a(double num){
		this->lambda_a = num;
	};
	double lambda_k_m(){
		return sqrt(  ( M_n * M_n*(k_b+1) / 2 ) / (1 + M_n * M_n*(k_b - 1)/ 2 )   );
	};
	
	double T_0_B(){
		return T_n/(1 - ( (k_b - 1) / (k_b + 1) ) * lambda_k_m() * lambda_k_m());
	};
	
	double betta_func(){
		this->betta = (n+1)/n;
		return betta;
	};
	
	
	double kappa_func(){
		this->kappa = sqrt( ( (k+1)*k_b * R ) / ((k_b+1)*k * R_b) );
		return kappa;
	};
	
	double tetta_tetta_func(){
		this->tetta_tetta = sqrt(T_p/T_0_B());
		return tetta_tetta;
	};
	double C_tetta_func(){
		this->C_tetta = betta * kappa *tetta_tetta;
		return C_tetta;
	};
	double z(double k, double lambda){
		return lambda + 1/lambda;
	}
	double f_vx_func() {
		this-> f_vx = (( (2 * f_a) / (M_n * M_n*k_b) ) + C_R )  /  ( ((fi_n*(k_b + 1)  / k_b) * C_tetta * (z( k,lambda_a)/ lambda_k_m())) - 2*fi_n - C_x_dop);
		return f_vx;
	}
	
	double a_kr_func(){
		this->a_kr = sqrt( (2* k_b * R_b * T_0_B()) / (k_b + 1) );
		return a_kr;
	};
	
	double V_n_func(){
		this->V_n =a_kr * lambda_k_m() ;
		return V_n;
	};
	
	double R_ud_func(){
		this->R_ud = (C_R * V_n * n) / ( 2 * fi_n * f_vx);
		return R_ud;
	};
	double q_for_lambda(){
		this->q_lambda = f_kr/(f_a*sigma_c);
		return q_lambda;
	};
	
	
};

int main(int argc, char *argv[]) {
	dvig d(3.2,   223.3,   1950,   1.27,   282,   1.4,   287,   0.6765,   0.5,    1,   1,     0,      16);
//		   M_n,    T_n,    T_p,      k,     R,    k_b,   R_b,   C_R,      f_kr,  f_a, fi_n, C_x_dop,  n
	std::cout<<"Лямбда от k_b и M_n: " << d.lambda_k_m()<<std::endl;
	std::cout <<"T_0_B: " << d.T_0_B()<<std::endl;
	std::cout <<"состовляющая бетта: " << d.betta_func()<<std::endl;
	std::cout <<"состовляющая каппа: " << d.kappa_func()<<std::endl;
	std::cout <<"состовляющая тетта тетта: " << d.tetta_tetta_func()<<std::endl;
	std::cout <<"С_тетта: " << d.C_tetta_func()<<std::endl;
	std::cout <<"q(k,lambda): " << d.q_for_lambda()<<std::endl;
	std::cout <<"далее определяешь значение lambda_a по таблице через q(lambda) и k: " <<std::endl;
	std::cout <<"введи lambda_a : " <<std::endl;
	double lambda_a;
	std::cin >> lambda_a;
	d.set_lambda_a(lambda_a);
	std::cout <<"f_vx: " << d.f_vx_func()<<std::endl;
	std::cout <<"a_kr: " << d.a_kr_func()<<std::endl;
	std::cout <<"V_n: " << d.V_n_func()<<std::endl;
	std::cout <<"R_ud: " << d.R_ud_func()<<std::endl;

	return 0;
}