#include <iostream>

int fibTailRecHealper(int value, int valueMinus1, int counter)
{
    if(counter == 0)
    {
        return valueMinus1;
    } else 
    {
        return fibTailRecHealper(value + valueMinus1, value, counter -1);
    }
}
int fibTailRec(int f) 
{
    return fibTailRecHealper(1, 0, f);
}

int recursivePowerof2Helper (int n, int result)
{
    if (n == 0)
    {
        return result;
    }
    else return recursivePowerof2Helper (n-1, result*2);
}
int recursivePowerof2 (int n)
{
    return recursivePowerof2Helper (n, 1);
}

int recursiveMultABHelper(int a, int b, int accumulator) 
{
    if (a <= 0 || b <= 0) 
    {
        return 0;
    }
    if (a == 1) 
    {
        return accumulator + b;
    }
    if (b == 1) 
    {
        return accumulator + a;
    }
    
    if (a <= b) 
    {
        return recursiveMultABHelper(a - 1, b, accumulator + b);
    } 
    else return recursiveMultABHelper(a, b - 1, accumulator + a);
}

int recursiveMultAB(int a, int b) 
{
    if (a == 0 || b == 0) 
    {
        return 0;
    }
    
    return recursiveMultABHelper(a, b, 0);
}

int recursiveFactHelper (int x, int sum)
{
    if (x == 0)
    {
        return sum;
    }
    else return recursiveFactHelper (x-1, sum * x);
}

int recursiveFact (int x)
{
    if (x < 0)
    {
        return -1;
    }
    return recursiveFactHelper (x,1);
}

int main() 
    {
        int f = 0;
        int resultFib = fibTailRec(f);
        std::cout<<"fib("<<f<<") = "<<resultFib<<std::endl;
        int f1 = 1;
        int resultFib1 = fibTailRec(f1);
        std::cout<<"fib("<<f1<<") = "<<resultFib1<<std::endl;
        int f2 = 5;
        int resultFib2 = fibTailRec(f2);
        std::cout<<"fib("<<f2<<") = "<<resultFib2<<std::endl;
        int f3 = 8;
        int resultFib3 = fibTailRec(f3);
        std::cout<<"fib("<<f3<<") = "<<resultFib3<<std::endl;
       
        std::cout<<"----------------"<<std::endl;

        int n = 0;
        int result = recursivePowerof2(n);
        std::cout << "power("<< n << ") = " << result << std::endl;
        int n1 = 1;
        int result1 = recursivePowerof2(n1);
        std::cout << "power("<< n1 << ") = " << result1 << std::endl;
        int n2 = 5;
        int result2 = recursivePowerof2(n2);
        std::cout << "power("<< n2 << ") = " << result2 << std::endl;
        int n3 = 8;
        int result3 = recursivePowerof2(n3);
        std::cout << "power("<< n3 << ") = " << result3 << std::endl;
        
        std::cout<<"----------------"<<std::endl;
        
        int a = 5;
        int b = 7;
        int result4 = recursiveMultAB(a, b);
        std::cout <<"multAB("<<a<<","<<b<<") = "<<result4 << std::endl;
        int a1 = 12;
        int b2 = 3;
        int result5 = recursiveMultAB(a1, b2);
        std::cout <<"multAB("<<a1<<","<<b2<<") = "<<result5 << std::endl;
         
        std::cout<<"----------------"<<std::endl;

        int x = 3;
        int result6 = recursiveFact(x);
        std::cout << "factorial("<<x<<") = " << result6 << std::endl;
        int x1 = 7;
        int result7 = recursiveFact(x1);
        std::cout << "factorial("<<x1<<") = " << result7 << std::endl;
        
        std::cout<<"----------------"<<std::endl;

        return 0;
    }