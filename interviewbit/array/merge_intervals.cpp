/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	int n = intervals.size();
	vector<Interval>::iterator it;
	it = intervals.begin();
	bool isInsert = false;
	for(int i=0;i<n;i++){
		if(intervals[i].start > newInterval.start){
			intervals.insert(it+i, 1, newInterval);
			isInsert = true;
			break;
		}
	}

	if(!isInsert){
		intervals.push_back(newInterval);
	}


	int i=1;
	while(i < intervals.size()){
		if(intervals[i].start > intervals[i-1].end){
			i++;
		}else if(intervals[i].end < intervals[i-1].end){
			intervals.erase(intervals.begin()+i);
		}else if(intervals[i].start < intervals[i-1].end){
			intervals[i-1].end = intervals[i].end;
			intervals.erase(intervals.begin()+i);
		}
	}
	

	return intervals;
}
