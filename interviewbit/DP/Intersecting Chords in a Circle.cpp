int Solution::chordCnt(int n){
	vector<long int> chords(n+1);

	chords[0] = 1;
	chords[1] = 1;

	long int den = 1000000007;
	for(int i=2;i<=n;i++){
		chords[i] = 0;
		for(int j=0;j<i;j++){
			chords[i] += ((chords[j]%den) * (chords[i-j-1]%den)) % den;
		}
	}

	return chords[n]%den;
}
