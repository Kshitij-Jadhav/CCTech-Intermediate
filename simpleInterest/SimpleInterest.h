class SimpleInterest {
public:
    int years;
    float interestRate, principle;
    float getSimpleInterest(int time, float interest, float amount){
        years = time;
        interestRate = interest;
        principle = amount;
        return (float)(principle * interestRate * years)/100;
    }
};