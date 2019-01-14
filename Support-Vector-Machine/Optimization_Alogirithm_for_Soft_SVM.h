#ifndef QPG_H
#define QPG_H

class QPG
{
public:
    QPG(){}
    void input(double **A,double *b,double **C,double *c,int m,int r,int n);
//
//  The following functions are used for both LP and QP
//
    double CPROD(double **C,double *x,int n);
    double PROD(double *c,double *x,int n);
    void PHI(double **DINV,double *d,int n,int &k);
    void PHI1(double **DINV,double *d,int n,int &k,int *J);
    void PHI2(double **DINV,double *d,int n,int &mu,int *J);
//
//  The following is LP code
//
    void LPSUB(double **A,double *b,double *c,double *x,double **DINV,
                double &optV,int &m,int &n,int *J,int &JOUT);
    void STEP11(double *c,double **DINV,double &v,int *J,int n,int &k);
    void STEP12(double *c,double **DINV,int *J,int m,int n,int &k,int &step2);
    void STEP2(double **A,double *s,double &sigma,double *x,double *b,
                int *J,int &l,int m,int n,int &step3);
    void STEP3(double *x,double **A,double **DINV,double &sigma,double *c,
                double *s,double &optV,int *J,int n,int &k,int &l);
//
//  The following is QP code
// 
    void QPSOLN(double *y,double &optV,int &JOUT);
    void QPSUB(double **A,double *b,double **C,double *c,double *x,
                double **DINV,double &optV,int m,int n,int *J,int &JOUT);
    void QSTEP11(double *c,double **DINV,double &v,int *J,int n,int &k);
    void QSTEP12(double *c,double **DINV,int *J,int m,int n,int &k,int &step2);
    void QSTEP2(double **A,double *s,double &sigma1,double &sigma2,
                double **C,double *x,double *c,double *b,
                int *J,int &l,int m,int n,int &step3);
    void QSTEP3(double *x,double **A,double **DINV,double &sigma1,double &sigma2,
		double *s,double **C,double *c,double *g,double &optV,int *J,
		int n,int &k,int &l); 

private:
    int m1,r1,n1,*J1,JOUT1;
    double **A1,*b1,**C1,*c1,optV1;
};
#endif

