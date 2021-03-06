#include "disp.c"
#include "os_call.c"
#include "string.c"

#define DO		(440)
#define DO_S	(466)
#define RE		(494)
#define RE_S	(523)
#define MI		(554)
#define FA		(587)
#define FA_S	(622)
#define SO		(659)
#define SO_S	(698)
#define RA		(740)
#define RA_S	(784)
#define SI		(831)



#define H1 (60*1000/60)					// 60
#define H2 (60*1000/76)					// 76

const int dongirikorokoro[70][2]={
	SO,   H1/2,
	MI,   H1/4,
	0,		H1/20,
	MI,   H1/4,
	FA,   H1/4,
	MI,   H1/4,
	RE,   H1/4,
	DO,   H1/4,
	
	SO,   H1/4,
	0,		H1/20,
	SO,   H1/4,
	MI,   H1/4,
	0,		H1/20,
	MI,   H1/4,
	RE,   H1/2,
	0,    H1/2,
	
	MI,		H1/4,
	0,		H1/20,
	MI,		H1/4,
	SO,		H1/4,
	0,		H1/20,
	SO,		H1/4,
	RA,		H1/4,
	0,		H1/20,
	RA,		H1/4,
	0,		H1/20,
	RA,		H1/4,
	0,		H1/20,
	RA,		H1/4,
	DO*2,	H1/4,
	0,		H1/20,
	DO*2,	H1/4,
	MI,		H1/4,
	0,		H1/20,
	MI,		H1/4,
	SO,		H1/2,
	0,		H1/2,
	
	SO,		H1/4,
	0,		H1/20,
	SO,		H1/4,
	MI,		H1/4,
	0,		H1/20,
	MI,		H1/4,
	FA,		H1/4,
	MI,		H1/4,
	RE,		H1/4,
	DO,		H1/4,
	SO,		H1/4,
	0,		H1/20,
	SO,		H1/4,
	MI,		H1/4,
	0,		H1/20,
	MI,		H1/4,
	RE,		H1/2,
	0,		H1/2,
	
	SO,		H1/2,
	MI,		H1/2,
	RA,		H1/2,
	SO,		H1/4,
	0,		H1/20,
	SO,		H1/4,
	RA,		H1/4,
	0,		H1/20,
	RA,		H1/4,
	SI,		H1/4,
	0,		H1/20,
	SI,		H1/4,
	DO*2,	H1/2,
	0,		1000,
	
	0,0,
};

const int aoimenoningyou[200][2]={
	SI,		H2*3/4,	
	DO_S*2,	H2/4,
	SI,		H2/2,
	SO_S,	H2/2,
	SI,		H2/2,
	SO_S,	H2/4,
	FA_S,	H2/4,
	MI,		H2/2,
	0,		H2/20,
	MI,		H2/2,
	FA_S,	H2/2,
	SO_S,	H2/2,
	SI/2,	H2/2,
	0,		H2/20,
	SI/2,	H2/2,
	0,		H2/20,
	SI/2,	H2,
	0,		H2,
	
	DO_S,	H2/2,
	SI/2,	H2/2,
	DO_S,	H2/2,
	SI/2,	H2/2,
	DO_S,	H2/2,
	MI,		H2/2,
	FA_S,	H2/2,
	SO_S,	H2/2,
	SI,		H2*3/2,
	DO_S*2,	H2/2,
	SO_S,	H2/2,
	MI,		H2/2,
	FA_S,	H2,
	DO_S*2,	H2*3/4,
	SI,		H2*3/4,
	DO_S*2,	H2*3/4,
	SI,		H2*3/4,
	DO_S*2,	H2*3/4,
	MI*2,	H2*3/4,
	FA_S*2,	H2*3/4,
	SO_S*2,	H2*3/4,
	
	SI*2,	H2*3/2,
	DO_S*4,	H2/2,
	SO_S*2,	H2/2,
	MI*2,	H2/2,
	FA_S*2,	H2,
	//----------------
	SI,		H2/2,
	0,		H2/20,
	SI,		H2/2,
	0,		H2/20,
	SI,		H2/2,
	RA,		H2/2,
	SI,		H2/2,
	0,		H2/20,
	SI,		H2/2,
	0,		H2/20,
	SI,		H2/2,
	RA,		H2/2,
	SI,		H2/2,
	DO*2,	H2/2,
	0,		H2/20,
	DO*2,	H2/2,
	RA,		H2/2,
	SI,		H2*3/2,
	SO,		H2/2,
	
	0,		H2/20,
	SO,		H2/2,
	0,		H2/20,
	SO,		H2/2,
	0,		H2/20,
	SO,		H2/2,
	FA_S,	H2/2,
	SO,		H2/2,
	0,		H2/20,
	SO,		H2/2,
	0,		H2/20,
	SO,		H2/2,
	FA_S,	H2/2,
	SO,		H2/2,
	SI,		H2/2,
	MI,		H2/2,
	0,		H2/20,
	MI,		H2/2,
	FA_S,	H2,
	0,		H2,
	SI,		H2/2,
	0,		H2/20,
	SI,		H2/2,
	0,		H2/20,
	SI,		H2/2,
	RA,		H2/2,
	SI,		H2/2,
	0,		H2/20,
	SI,		H2/2,
	0,		H2/20,
	SI,		H2/2,
	RA,		H2/2,
	
	SI,		H2/2,
	DO*2,	H2/2,
	0,		H2/20,
	DO*2,	H2/2,
	RA,		H2/2,
	SI,		H2,
	SO,		H2/2,
	0,		H2/20,
	SO,		H2/2,
	0,		H2/20,
	SO,		H2/2,
	0,		H2/20,
	SO,		H2/2,
	FA_S,	H2/2,
	SO,		H2/2,
	0,		H2/20,
	SO,		H2/2,
	0,		H2/20,
	SO,		H2/2,
	FA_S,	H2/2,
	SO,		H2/2,
	SI,		H2/2,
	MI,		H2/2,
	0,		H2/20,
	MI,		H2/2,
	FA_S,	H2/2,
	0,		H2,
	
	SI,		H2*3/4,
	DO_S,	H2/4,
	SI,		H2/2,
	SO_S,	H2/2,
	SI,		H2/2,
	SO_S,	H2/4,
	FA_S,	H2/4,
	MI,		H2/2,
	0,		H2/20,
	MI,		H2/2,
	FA_S,	H2/2,
	SO_S,	H2/2,
	SI/2,	H2/2,
	0,		H2/20,
	SI/2,	H2/2,
	0,		H2/20,
	SI/2,	H2,
	0,		H2,
	DO_S,	H2/2,
	SI/2,	H2/2,
	DO_S,	H2/2,
	SI/2,	H2/2,
	DO_S,	H2/2,
	MI,		H2/2,
	FA_S,	H2/2,
	SO_S,	H2/2,
	
	SI,		H2*3/2,
	DO_S*2,	H2/2,
	SO_S,	H2/2,
	MI,		H2/2,
	FA_S,	H2,
	DO_S,	H2/2,
	SI/2,	H2/2,
	DO_S,	H2/2,
	SI/2,	H2/2,
	DO_S,	H2/2,
	MI,		H2/2,
	FA_S,	H2/2,
	SO_S,	H2/2,
	SI,		H2*3/2,
	DO_S*2,	H2/2,
	SO_S,	H2/2,
	FA_S,	H2/2,
	MI,		H2,
	
	0,0,
};

/********************************************************************************/
/*		music_main																*/
/********************************************************************************/
void main()
{
	int cmd;
	
	for(;;){
		play_music(dongirikorokoro);
		play_music(aoimenoningyou);
	}
}
/********************************************************************************/
/*		play_music																*/
/********************************************************************************/
void play_music(int tbl[100][2])
{
	int i;
	
	for(i=0; ; i++){
		if(tbl[i][0]==0 && tbl[i][1]==0){
			wait_music(3000);
			return;
		}
		if(tbl[i][0]==0){
			wait_music(tbl[i][1]);
		}
		else{
			buzzer_wait(tbl[i][0], tbl[i][1]);
		}
	}
}
/********************************************************************************/
/*		wait_music																*/
/********************************************************************************/
void wait_music(uint msec)
{
	uint time1;
	
	time1 = GetTickCount();
	while(GetTickCount()-time1 < msec)
		;
}
