class Solution {
public:
    vector<int> Months ;

    int dateToNumber(string date)
    {
        int month = stoi( date.substr(0,2) ) ;
        int ans = 0 ;
        for ( int i = 0 ; i < month ; i++ ) ans += Months[i] ;
        ans += stoi( date.substr(3,2) ) ;
        return ans ;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) 
    {
        Months = {0,31,28,31,30,31,30,31,31,30,31,30,31} ; 

        int aliceArrive = dateToNumber(arriveAlice) ;
        int aliceLeave = dateToNumber(leaveAlice) ;

        int bobArrive = dateToNumber(arriveBob) ;
        int bobLeave = dateToNumber(leaveBob) ;

        return max( 0 , min( aliceLeave , bobLeave  ) - max( aliceArrive , bobArrive ) + 1 ) ;
        
    }
};