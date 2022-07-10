#ifndef MATRICES_H
#define MATRICES_H


class matrices {
private:
    float matriz;

public:
    matrices();
    void setMatriz();
    float getMatriz()const;
    void setMatrizSuma(float m1,float m2);
    void setMatrizMult(float m1,float m2);
};

#endif // MATRICES_H
