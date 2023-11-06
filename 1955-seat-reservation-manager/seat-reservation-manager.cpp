class SeatManager {
    set<int> seats;
    int mini;
public:
    SeatManager(int n) {
         mini=1;     
    }
    
    int reserve() {
        if(!seats.empty()){
            int seating= *seats.begin();
             seats.erase(seats.begin());
              return seating;   
        } 
        else
        {
            int seating= mini;
            mini++;
            return seating;
        }
          
    }
    
    void unreserve(int seatNumber) {
        seats.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */