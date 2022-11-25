class SimpleInterest {
public:
    int years;
    float interestRate, principle;
    float getSimpleInterest(int time, float interest, float amount){
        years = time;
        interestRate = interest;
        principle = amount;
        return (principle * (1+(interestRate * years)));
    }
};