/**********************************************************************/
/*                                                                    */
/* Program Name: Convert  -  Convert Disk Block Values                */
/* Author:       Dave Safanyuk                                        */
/* Installation: Pensacola Christian College, Pensacola, Florida      */
/* Course:       CS326, Operating Systems                             */
/* Date Written: April 03, 2019                                       */
/*								                                              */
/**********************************************************************/

/**********************************************************************/
/*                                                                    */
/* I pledge  the C language  statements in  this  program are  my own */
/* original  work,  and none  of the  C language  statements in  this */
/* program were copied  from any one else,  unless I was specifically  */
/* authorized to do so by my CS326 instructor.                        */
/*                                                                    */
/*                                                                    */
/*                           Signed: ________________________________ */
/*                                             (signature)            */
/*                                                                    */
/**********************************************************************/

/**********************************************************************/
/*                                                                    */
/* This program prints disk blocks up to 360 along with the           */
/* corresponding converted cylinder, track, and sector numbers.       */
/*                                                                    */
/**********************************************************************/

#include <stdio.h>  /* printf, scanf                                  */

/**********************************************************************/
/*                          Symbolic Constants                        */
/**********************************************************************/
#define BYTES_PER_SECTOR    512  /* Number of bytes per sector         */
#define CYLINDERS_PER_DISK  40   /* Number of cylinders on the disk    */
#define SECTORS_PER_TRACK   9    /* Number of sector per track         */
#define TRACKS_PER_CYLINDER 2    /* Number of tracks per cylinder      */
#define SECTORS_PER_BLOCK   2    /* Number of sector per block         */

/**********************************************************************/
/*                          Function Prototypes                       */
/**********************************************************************/
void convert(int block, int *p_cylinder, int *p_track, int *p_sector);
	/* Converts block number into cylinder, track and sector numbers   */

/**********************************************************************/
/*                            Main Function                           */
/**********************************************************************/
int main()
{	
   int block_number_count, /* Current block  number                   */
       cylinder,           /* Current cylinder number                 */
       max_block_number,   /* Maximum blocks available on the disk    */
       sector,             /* Current sector number                   */
       track;              /* Current track  number                   */

   max_block_number = (CYLINDERS_PER_DISK * SECTORS_PER_TRACK * 
                              TRACKS_PER_CYLINDER / SECTORS_PER_BLOCK);

   printf("\nBlock     Cyclinder      Track     Sector ");
   printf("\n-----     ---------      -----     -------");
   for (block_number_count = 1; block_number_count <= max_block_number;
                                                   block_number_count++)
   {
      convert(block_number_count, &cylinder, &track, &sector);

      printf("\n %2d         ", block_number_count);
      printf("%2d             ", cylinder);
      printf("%d          ", track);
      printf("%d", sector);


   }
	return 0;
}

/**********************************************************************/
/*    Convert Block Number into Cylinder, Track, and Sector Numbers   */
/**********************************************************************/
void convert(int block, int *p_cylinder, int *p_track, int *p_sector)
{
	*p_cylinder = ((block - 1) / SECTORS_PER_TRACK);

	if(((float)((block - 1) % SECTORS_PER_TRACK)) < 4.5f)
		*p_track = 0;
	else
		*p_track = 1;

	if ((((block - 1) % SECTORS_PER_TRACK) * 2) < 9)
		*p_sector = (((block - 1) % SECTORS_PER_TRACK) * 2);
	else
		*p_sector = (((block - 1) % SECTORS_PER_TRACK) * 2) - 9;
	return;
}
