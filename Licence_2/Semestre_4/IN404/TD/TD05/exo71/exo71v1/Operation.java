
public enum Operation
{   


    PLUS('+'){
        public double eval(double o1,double o2){
            return o1+o2;
        }
    },
    
    MOINS('-'){
      public double eval(double o1,double o2){
          return o1-o2;
        }
    },
    
    FOIS('*'){
        public double eval(double o1,double o2){
            return o1*o2;
        }
    },
    
    DIVISE('/'){
        public double eval(double o1,double o2){
            return o1/o2;
        }
    };
    
    private char symbole;
    
    private Operation(char symbole){
        this.symbole=symbole;
    }
    public abstract double eval(double o1,double o2);
    
    public char getSymbole(){
        return this.symbole;
    }
}
