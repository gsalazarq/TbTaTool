#define TimeToolForRun_cxx
#include "TimeToolForRun.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "Riostream.h"
	#include <fstream>


void TimeToolForRun::Loop()
{
    const char* name_file[1000] = {



											// 8 GeV Pos

											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0001_cosmc_v09_1504240117_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0002_cosmc_v09_1504240120_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0003_cosmc_v09_1504240126_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0004_cosmc_v09_1504240133_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0005_cosmc_v09_1504240139_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0006_cosmc_v09_1504240146_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0007_cosmc_v09_1504240153_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0008_cosmc_v09_1504240201_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0009_cosmc_v09_1504240208_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0010_cosmc_v09_1504240215_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0011_cosmc_v09_1504240222_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0012_cosmc_v09_1504240237_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0013_cosmc_v09_1504240253_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0014_cosmc_v09_1504240308_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0015_cosmc_v09_1504240317_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0016_cosmc_v09_1504240324_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0017_cosmc_v09_1504240333_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0018_cosmc_v09_1504240339_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0019_cosmc_v09_1504240349_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0020_cosmc_v09_1504240356_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0021_cosmc_v09_1504240403_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0022_cosmc_v09_1504240409_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0023_cosmc_v09_1504240415_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0024_cosmc_v09_1504240422_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0025_cosmc_v09_1504240428_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0026_cosmc_v09_1504240431_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0027_cosmc_v09_1504240438_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0028_cosmc_v09_1504240444_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0029_cosmc_v09_1504240450_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0030_cosmc_v09_1504240456_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0031_cosmc_v09_1504240502_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0032_cosmc_v09_1504240508_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0033_cosmc_v09_1504240515_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0034_cosmc_v09_1504240521_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0035_cosmc_v09_1504240527_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0036_cosmc_v09_1504240533_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0037_cosmc_v09_1504240541_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0038_cosmc_v09_1504240547_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0039_cosmc_v09_1504240554_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0040_cosmc_v09_1504240601_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0041_cosmc_v09_1504240607_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0042_cosmc_v09_1504240613_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0043_cosmc_v09_1504240620_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0044_cosmc_v09_1504240626_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0045_cosmc_v09_1504240632_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0046_cosmc_v09_1504240639_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0047_cosmc_v09_1504240647_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0048_cosmc_v09_1504240656_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0049_cosmc_v09_1504240702_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0050_cosmc_v09_1504240711_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0051_cosmc_v09_1504240719_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0052_cosmc_v09_1504240728_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0053_cosmc_v09_1504240734_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0054_cosmc_v09_1504240741_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0055_cosmc_v09_1504240753_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0056_cosmc_v09_1504240803_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0057_cosmc_v09_1504240810_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0058_cosmc_v09_1504240817_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0059_cosmc_v09_1504240823_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0060_cosmc_v09_1504240830_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0061_cosmc_v09_1504240837_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0062_cosmc_v09_1504240843_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0063_cosmc_v09_1504240849_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0064_cosmc_v09_1504240855_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0065_cosmc_v09_1504240901_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0066_cosmc_v09_1504240907_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0067_cosmc_v09_1504240914_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0068_cosmc_v09_1504240920_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0069_cosmc_v09_1504240926_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0070_cosmc_v09_1504240932_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0071_cosmc_v09_1504240938_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0072_cosmc_v09_1504240944_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0073_cosmc_v09_1504240950_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Pos_Pions/TB_00001514_0074_cosmc_v09_1504240956_camac.root",

											// 6 GeV Pos

											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001517_0001_cosmc_v09_1504241040_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001517_0002_cosmc_v09_1504241046_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001517_0003_cosmc_v09_1504241052_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001517_0004_cosmc_v09_1504241059_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001517_0005_cosmc_v09_1504241105_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001517_0006_cosmc_v09_1504241112_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001517_0007_cosmc_v09_1504241119_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001517_0008_cosmc_v09_1504241125_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001517_0009_cosmc_v09_1504241132_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001517_0010_cosmc_v09_1504241138_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001517_0011_cosmc_v09_1504241144_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001517_0012_cosmc_v09_1504241151_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001517_0013_cosmc_v09_1504241157_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001517_0014_cosmc_v09_1504241204_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001517_0015_cosmc_v09_1504241211_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001517_0016_cosmc_v09_1504241217_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001517_0017_cosmc_v09_1504241224_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001517_0018_cosmc_v09_1504241230_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001517_0019_cosmc_v09_1504241237_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001517_0020_cosmc_v09_1504241244_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001517_0021_cosmc_v09_1504241250_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001517_0022_cosmc_v09_1504241256_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001517_0023_cosmc_v09_1504241303_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001517_0024_cosmc_v09_1504241310_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001517_0025_cosmc_v09_1504241316_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001518_0001_cosmc_v09_1504241323_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001518_0002_cosmc_v09_1504241330_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001518_0003_cosmc_v09_1504241337_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001518_0004_cosmc_v09_1504241343_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001518_0005_cosmc_v09_1504241350_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001518_0006_cosmc_v09_1504241357_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001518_0007_cosmc_v09_1504241403_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001518_0008_cosmc_v09_1504241410_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001518_0009_cosmc_v09_1504241417_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001518_0010_cosmc_v09_1504241423_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001518_0011_cosmc_v09_1504241429_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001518_0012_cosmc_v09_1504241435_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001518_0013_cosmc_v09_1504241442_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001518_0014_cosmc_v09_1504241448_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001518_0015_cosmc_v09_1504241454_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001518_0016_cosmc_v09_1504241501_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001519_0001_cosmc_v09_1504241721_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001519_0002_cosmc_v09_1504241727_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001519_0003_cosmc_v09_1504241734_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001519_0004_cosmc_v09_1504241740_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001519_0005_cosmc_v09_1504241747_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001519_0006_cosmc_v09_1504241753_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001519_0007_cosmc_v09_1504241800_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001519_0008_cosmc_v09_1504241806_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001519_0009_cosmc_v09_1504241812_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001519_0010_cosmc_v09_1504241829_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001519_0011_cosmc_v09_1504241835_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001519_0012_cosmc_v09_1504241842_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001519_0013_cosmc_v09_1504241849_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001519_0014_cosmc_v09_1504241855_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001519_0015_cosmc_v09_1504241901_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001519_0016_cosmc_v09_1504241909_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001519_0017_cosmc_v09_1504241915_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001519_0018_cosmc_v09_1504241922_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001519_0019_cosmc_v09_1504241928_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001519_0020_cosmc_v09_1504241935_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001519_0021_cosmc_v09_1504241942_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001519_0022_cosmc_v09_1504241944_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001519_0023_cosmc_v09_1504241951_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001519_0024_cosmc_v09_1504241958_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001519_0025_cosmc_v09_1504242005_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001520_0001_cosmc_v09_1504242012_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001520_0002_cosmc_v09_1504242018_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001520_0003_cosmc_v09_1504242025_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001520_0004_cosmc_v09_1504242031_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Pos_Pions/TB_00001520_0005_cosmc_v09_1504242038_camac.root",

											// 4 GeV Pos

											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0001_cosmc_v09_1504242123_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0002_cosmc_v09_1504242130_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0003_cosmc_v09_1504242137_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0004_cosmc_v09_1504242143_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0005_cosmc_v09_1504242152_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0006_cosmc_v09_1504242159_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0007_cosmc_v09_1504242206_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0008_cosmc_v09_1504242213_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0009_cosmc_v09_1504242220_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0010_cosmc_v09_1504242227_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0011_cosmc_v09_1504242234_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0012_cosmc_v09_1504242242_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0013_cosmc_v09_1504242250_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0014_cosmc_v09_1504242257_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0015_cosmc_v09_1504242304_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0016_cosmc_v09_1504242311_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0017_cosmc_v09_1504242319_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0018_cosmc_v09_1504242326_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0019_cosmc_v09_1504242333_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0020_cosmc_v09_1504242340_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0021_cosmc_v09_1504242348_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0022_cosmc_v09_1504242356_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0023_cosmc_v09_1504250003_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0024_cosmc_v09_1504250010_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0025_cosmc_v09_1504250016_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0026_cosmc_v09_1504250024_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0027_cosmc_v09_1504250031_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0028_cosmc_v09_1504250038_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0029_cosmc_v09_1504250045_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0030_cosmc_v09_1504250053_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0031_cosmc_v09_1504250101_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0032_cosmc_v09_1504250109_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0033_cosmc_v09_1504250116_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0034_cosmc_v09_1504250123_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0035_cosmc_v09_1504250131_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0036_cosmc_v09_1504250138_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0037_cosmc_v09_1504250145_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0038_cosmc_v09_1504250152_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0039_cosmc_v09_1504250200_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0040_cosmc_v09_1504250207_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0041_cosmc_v09_1504250213_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0042_cosmc_v09_1504250220_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0043_cosmc_v09_1504250227_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0044_cosmc_v09_1504250234_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0045_cosmc_v09_1504250241_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0046_cosmc_v09_1504250248_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0047_cosmc_v09_1504250255_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0048_cosmc_v09_1504250302_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0049_cosmc_v09_1504250309_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0050_cosmc_v09_1504250315_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0051_cosmc_v09_1504250323_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0052_cosmc_v09_1504250330_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0053_cosmc_v09_1504250337_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0054_cosmc_v09_1504250344_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0055_cosmc_v09_1504250508_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0056_cosmc_v09_1504250514_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0057_cosmc_v09_1504250522_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0058_cosmc_v09_1504250530_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0059_cosmc_v09_1504250537_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0060_cosmc_v09_1504250544_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0061_cosmc_v09_1504250552_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0062_cosmc_v09_1504250601_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0063_cosmc_v09_1504250608_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0064_cosmc_v09_1504250615_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0065_cosmc_v09_1504250622_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0066_cosmc_v09_1504250629_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0067_cosmc_v09_1504250636_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0068_cosmc_v09_1504250643_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0069_cosmc_v09_1504250650_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0070_cosmc_v09_1504250658_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0071_cosmc_v09_1504250705_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0072_cosmc_v09_1504250712_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0073_cosmc_v09_1504250719_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Pos_Pions/TB_00001522_0074_cosmc_v09_1504250726_camac.root",

											// 8 GeV Neg


											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0001_cosmc_v09_1504250801_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0002_cosmc_v09_1504250807_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0003_cosmc_v09_1504250814_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0004_cosmc_v09_1504250820_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0005_cosmc_v09_1504250826_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0006_cosmc_v09_1504250833_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0007_cosmc_v09_1504250839_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0008_cosmc_v09_1504250846_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0009_cosmc_v09_1504250852_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0010_cosmc_v09_1504250858_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0011_cosmc_v09_1504250904_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0012_cosmc_v09_1504250910_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0013_cosmc_v09_1504250916_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0014_cosmc_v09_1504250922_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0015_cosmc_v09_1504250928_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0016_cosmc_v09_1504250936_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0017_cosmc_v09_1504250943_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0018_cosmc_v09_1504250949_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0019_cosmc_v09_1504250955_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0020_cosmc_v09_1504251002_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0021_cosmc_v09_1504251009_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0022_cosmc_v09_1504251015_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0023_cosmc_v09_1504251021_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0024_cosmc_v09_1504251028_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0025_cosmc_v09_1504251034_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0026_cosmc_v09_1504251041_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0027_cosmc_v09_1504251047_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0028_cosmc_v09_1504251054_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0029_cosmc_v09_1504251100_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0030_cosmc_v09_1504251106_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0031_cosmc_v09_1504251113_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0032_cosmc_v09_1504251119_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0033_cosmc_v09_1504251125_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0034_cosmc_v09_1504251132_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0035_cosmc_v09_1504251138_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0036_cosmc_v09_1504251144_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0037_cosmc_v09_1504251150_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0038_cosmc_v09_1504251156_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0039_cosmc_v09_1504251202_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0040_cosmc_v09_1504251208_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0041_cosmc_v09_1504251215_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0042_cosmc_v09_1504251221_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0043_cosmc_v09_1504251227_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0044_cosmc_v09_1504251233_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0045_cosmc_v09_1504251240_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0046_cosmc_v09_1504251246_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0047_cosmc_v09_1504251252_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0048_cosmc_v09_1504251258_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0049_cosmc_v09_1504251304_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0050_cosmc_v09_1504251310_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0051_cosmc_v09_1504251318_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0052_cosmc_v09_1504251325_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0053_cosmc_v09_1504251332_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0054_cosmc_v09_1504251338_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0055_cosmc_v09_1504251345_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0056_cosmc_v09_1504251351_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0057_cosmc_v09_1504251357_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0058_cosmc_v09_1504251403_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0059_cosmc_v09_1504251411_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0060_cosmc_v09_1504251418_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0061_cosmc_v09_1504251424_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0062_cosmc_v09_1504251430_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0063_cosmc_v09_1504251438_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0064_cosmc_v09_1504251445_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0065_cosmc_v09_1504251452_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0066_cosmc_v09_1504251459_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0067_cosmc_v09_1504251505_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/8GeV_Neg_Pions/TB_00001524_0068_cosmc_v09_1504251512_camac.root",

											// 6 GeV Neg

											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0001_cosmc_v09_1504251551_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0002_cosmc_v09_1504251557_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0003_cosmc_v09_1504251604_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0004_cosmc_v09_1504251611_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0005_cosmc_v09_1504251617_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0006_cosmc_v09_1504251625_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0007_cosmc_v09_1504251631_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0008_cosmc_v09_1504251638_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0009_cosmc_v09_1504251644_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0010_cosmc_v09_1504251650_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0011_cosmc_v09_1504251656_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0012_cosmc_v09_1504251703_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0013_cosmc_v09_1504251709_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0014_cosmc_v09_1504251715_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0015_cosmc_v09_1504251722_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0016_cosmc_v09_1504251728_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0017_cosmc_v09_1504251735_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0018_cosmc_v09_1504251741_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0019_cosmc_v09_1504251747_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0020_cosmc_v09_1504251753_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0021_cosmc_v09_1504251800_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0022_cosmc_v09_1504251807_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0023_cosmc_v09_1504251814_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0024_cosmc_v09_1504251820_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0025_cosmc_v09_1504251827_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0026_cosmc_v09_1504251835_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0027_cosmc_v09_1504251842_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0028_cosmc_v09_1504251849_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0029_cosmc_v09_1504251856_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0030_cosmc_v09_1504251902_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0031_cosmc_v09_1504251908_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0032_cosmc_v09_1504251915_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0033_cosmc_v09_1504251921_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0034_cosmc_v09_1504251927_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0035_cosmc_v09_1504251934_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0036_cosmc_v09_1504251940_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0037_cosmc_v09_1504251946_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0038_cosmc_v09_1504251953_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0039_cosmc_v09_1504252000_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0040_cosmc_v09_1504252007_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0041_cosmc_v09_1504252014_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0042_cosmc_v09_1504252020_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0043_cosmc_v09_1504252027_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0044_cosmc_v09_1504252033_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0045_cosmc_v09_1504252040_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0046_cosmc_v09_1504252046_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0047_cosmc_v09_1504252052_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0048_cosmc_v09_1504252059_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0049_cosmc_v09_1504252106_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0050_cosmc_v09_1504252112_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0051_cosmc_v09_1504252119_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0052_cosmc_v09_1504252125_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0053_cosmc_v09_1504252132_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0054_cosmc_v09_1504252139_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0055_cosmc_v09_1504252145_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0056_cosmc_v09_1504252152_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0057_cosmc_v09_1504252158_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0058_cosmc_v09_1504252205_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0059_cosmc_v09_1504252211_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0060_cosmc_v09_1504252218_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0061_cosmc_v09_1504252224_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0062_cosmc_v09_1504252231_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0063_cosmc_v09_1504252237_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0064_cosmc_v09_1504252243_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0065_cosmc_v09_1504252250_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0066_cosmc_v09_1504252257_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0067_cosmc_v09_1504252304_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0068_cosmc_v09_1504252310_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/6GeV_Neg_Pions/TB_00001526_0069_cosmc_v09_1504252316_camac.root",

											// 4 GeV Neg


											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0001_cosmc_v09_1504252347_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0002_cosmc_v09_1504252355_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0003_cosmc_v09_1504260003_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0004_cosmc_v09_1504260010_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0005_cosmc_v09_1504260019_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0006_cosmc_v09_1504260026_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0007_cosmc_v09_1504260033_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0008_cosmc_v09_1504260040_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0009_cosmc_v09_1504260047_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0010_cosmc_v09_1504260054_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0011_cosmc_v09_1504260101_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0012_cosmc_v09_1504260108_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0013_cosmc_v09_1504260115_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0014_cosmc_v09_1504260122_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0015_cosmc_v09_1504260128_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0016_cosmc_v09_1504260135_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0017_cosmc_v09_1504260142_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0018_cosmc_v09_1504260149_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0019_cosmc_v09_1504260156_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0020_cosmc_v09_1504260204_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0021_cosmc_v09_1504260211_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0022_cosmc_v09_1504260219_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0023_cosmc_v09_1504260227_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0024_cosmc_v09_1504260234_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0025_cosmc_v09_1504260241_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0026_cosmc_v09_1504260249_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0027_cosmc_v09_1504260256_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0028_cosmc_v09_1504260303_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0029_cosmc_v09_1504260310_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0030_cosmc_v09_1504260317_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0031_cosmc_v09_1504260324_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0032_cosmc_v09_1504260331_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0033_cosmc_v09_1504260338_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0034_cosmc_v09_1504260345_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0035_cosmc_v09_1504260353_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0036_cosmc_v09_1504260400_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0037_cosmc_v09_1504260407_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0038_cosmc_v09_1504260414_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0039_cosmc_v09_1504260422_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0040_cosmc_v09_1504260429_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0041_cosmc_v09_1504260436_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0042_cosmc_v09_1504260443_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0043_cosmc_v09_1504260450_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0044_cosmc_v09_1504260457_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0045_cosmc_v09_1504260504_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0046_cosmc_v09_1504260511_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0047_cosmc_v09_1504260518_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0048_cosmc_v09_1504260524_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0049_cosmc_v09_1504260532_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0050_cosmc_v09_1504260539_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0051_cosmc_v09_1504260547_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0052_cosmc_v09_1504260554_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0053_cosmc_v09_1504260602_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0054_cosmc_v09_1504260609_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0055_cosmc_v09_1504260616_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0056_cosmc_v09_1504260623_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0057_cosmc_v09_1504260630_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0058_cosmc_v09_1504260637_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0059_cosmc_v09_1504260644_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0060_cosmc_v09_1504260651_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0061_cosmc_v09_1504260658_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0062_cosmc_v09_1504260705_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0063_cosmc_v09_1504260712_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0064_cosmc_v09_1504260718_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0065_cosmc_v09_1504260725_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0066_cosmc_v09_1504260732_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0067_cosmc_v09_1504260740_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0068_cosmc_v09_1504260746_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0069_cosmc_v09_1504260754_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0070_cosmc_v09_1504260801_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0071_cosmc_v09_1504260808_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0072_cosmc_v09_1504260815_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0073_cosmc_v09_1504260822_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/4GeV_Neg_Pions/TB_00001528_0074_cosmc_v09_1504260829_camac.root",

											// 9 GeV Pos
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0001_cosmc_v09_1504260859_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0002_cosmc_v09_1504260905_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0003_cosmc_v09_1504260911_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0004_cosmc_v09_1504260918_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0005_cosmc_v09_1504260924_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0006_cosmc_v09_1504260931_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0007_cosmc_v09_1504260937_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0008_cosmc_v09_1504260944_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0009_cosmc_v09_1504260950_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0010_cosmc_v09_1504260956_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0011_cosmc_v09_1504261002_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0012_cosmc_v09_1504261008_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0013_cosmc_v09_1504261014_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0014_cosmc_v09_1504261020_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0015_cosmc_v09_1504261026_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0016_cosmc_v09_1504261032_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0017_cosmc_v09_1504261038_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0018_cosmc_v09_1504261044_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0019_cosmc_v09_1504261050_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0020_cosmc_v09_1504261056_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0021_cosmc_v09_1504261102_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0022_cosmc_v09_1504261108_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0023_cosmc_v09_1504261114_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0024_cosmc_v09_1504261121_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0025_cosmc_v09_1504261127_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0026_cosmc_v09_1504261135_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0027_cosmc_v09_1504261141_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0028_cosmc_v09_1504261147_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0029_cosmc_v09_1504261153_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0030_cosmc_v09_1504261159_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0031_cosmc_v09_1504261205_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0032_cosmc_v09_1504261211_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0033_cosmc_v09_1504261218_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0034_cosmc_v09_1504261224_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0035_cosmc_v09_1504261230_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0036_cosmc_v09_1504261236_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0037_cosmc_v09_1504261242_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0038_cosmc_v09_1504261248_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0039_cosmc_v09_1504261254_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0040_cosmc_v09_1504261300_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0041_cosmc_v09_1504261306_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0042_cosmc_v09_1504261313_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0043_cosmc_v09_1504261319_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0044_cosmc_v09_1504261325_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0045_cosmc_v09_1504261332_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0046_cosmc_v09_1504261343_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0047_cosmc_v09_1504261350_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0048_cosmc_v09_1504261357_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0049_cosmc_v09_1504261404_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0050_cosmc_v09_1504261411_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0051_cosmc_v09_1504261420_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0052_cosmc_v09_1504261426_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0053_cosmc_v09_1504261432_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0054_cosmc_v09_1504261438_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0055_cosmc_v09_1504261444_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0056_cosmc_v09_1504261451_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0057_cosmc_v09_1504261456_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0058_cosmc_v09_1504261503_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0059_cosmc_v09_1504261509_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0060_cosmc_v09_1504261516_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0061_cosmc_v09_1504261522_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0062_cosmc_v09_1504261528_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0063_cosmc_v09_1504261534_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0064_cosmc_v09_1504261540_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0065_cosmc_v09_1504261546_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0066_cosmc_v09_1504261552_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0067_cosmc_v09_1504261559_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Pos_Pions/TB_00001530_0068_cosmc_v09_1504261605_camac.root",

											// 10 GeV Pos

											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0001_cosmc_v09_1504261635_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0002_cosmc_v09_1504261641_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0003_cosmc_v09_1504261647_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0004_cosmc_v09_1504261653_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0005_cosmc_v09_1504261700_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0006_cosmc_v09_1504261706_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0007_cosmc_v09_1504261713_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0008_cosmc_v09_1504261719_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0009_cosmc_v09_1504261726_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0010_cosmc_v09_1504261732_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0011_cosmc_v09_1504261738_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0012_cosmc_v09_1504261745_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0013_cosmc_v09_1504261751_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0014_cosmc_v09_1504261757_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0015_cosmc_v09_1504261803_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0016_cosmc_v09_1504261809_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0017_cosmc_v09_1504261815_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0018_cosmc_v09_1504261821_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0019_cosmc_v09_1504261828_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0020_cosmc_v09_1504261835_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0021_cosmc_v09_1504261841_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0022_cosmc_v09_1504261847_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0023_cosmc_v09_1504261854_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0024_cosmc_v09_1504261900_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0025_cosmc_v09_1504261906_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0026_cosmc_v09_1504261912_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0027_cosmc_v09_1504261919_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0028_cosmc_v09_1504261925_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0029_cosmc_v09_1504261931_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0030_cosmc_v09_1504261937_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0031_cosmc_v09_1504261943_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0032_cosmc_v09_1504261949_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0033_cosmc_v09_1504261956_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0034_cosmc_v09_1504262003_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0035_cosmc_v09_1504262009_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0036_cosmc_v09_1504262016_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0037_cosmc_v09_1504262023_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0038_cosmc_v09_1504262029_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0039_cosmc_v09_1504262035_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0040_cosmc_v09_1504262041_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0041_cosmc_v09_1504262047_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0042_cosmc_v09_1504262055_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0043_cosmc_v09_1504262101_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0044_cosmc_v09_1504262107_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0045_cosmc_v09_1504262113_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0046_cosmc_v09_1504262119_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0047_cosmc_v09_1504262125_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0048_cosmc_v09_1504262131_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0049_cosmc_v09_1504262137_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0050_cosmc_v09_1504262143_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0051_cosmc_v09_1504262149_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0052_cosmc_v09_1504262155_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0053_cosmc_v09_1504262201_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0054_cosmc_v09_1504262208_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0055_cosmc_v09_1504262214_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0056_cosmc_v09_1504262222_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0057_cosmc_v09_1504262228_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0058_cosmc_v09_1504262234_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0059_cosmc_v09_1504262240_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0060_cosmc_v09_1504262248_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0061_cosmc_v09_1504262254_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0062_cosmc_v09_1504262300_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0063_cosmc_v09_1504262306_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0064_cosmc_v09_1504262312_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Pos_Pions/TB_00001532_0065_cosmc_v09_1504262318_camac.root",

											// 16 GeV Pos

											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/16GeV_Pos_Pions/TB_00001534_0001_cosmc_v09_1504262340_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/16GeV_Pos_Pions/TB_00001534_0002_cosmc_v09_1504262347_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/16GeV_Pos_Pions/TB_00001534_0003_cosmc_v09_1504262353_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/16GeV_Pos_Pions/TB_00001534_0004_cosmc_v09_1504262359_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/16GeV_Pos_Pions/TB_00001534_0005_cosmc_v09_1504270005_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/16GeV_Pos_Pions/TB_00001534_0006_cosmc_v09_1504270013_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/16GeV_Pos_Pions/TB_00001534_0007_cosmc_v09_1504270019_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/16GeV_Pos_Pions/TB_00001534_0008_cosmc_v09_1504270025_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/16GeV_Pos_Pions/TB_00001534_0009_cosmc_v09_1504270032_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/16GeV_Pos_Pions/TB_00001534_0010_cosmc_v09_1504270039_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/16GeV_Pos_Pions/TB_00001534_0011_cosmc_v09_1504270045_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/16GeV_Pos_Pions/TB_00001534_0012_cosmc_v09_1504270051_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/16GeV_Pos_Pions/TB_00001534_0013_cosmc_v09_1504270057_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/16GeV_Pos_Pions/TB_00001534_0014_cosmc_v09_1504270103_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/16GeV_Pos_Pions/TB_00001534_0015_cosmc_v09_1504270109_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/16GeV_Pos_Pions/TB_00001534_0016_cosmc_v09_1504270115_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/16GeV_Pos_Pions/TB_00001534_0017_cosmc_v09_1504270121_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/16GeV_Pos_Pions/TB_00001534_0018_cosmc_v09_1504270127_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/16GeV_Pos_Pions/TB_00001534_0019_cosmc_v09_1504270133_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/16GeV_Pos_Pions/TB_00001534_0020_cosmc_v09_1504270139_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/16GeV_Pos_Pions/TB_00001534_0021_cosmc_v09_1504270145_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/16GeV_Pos_Pions/TB_00001534_0022_cosmc_v09_1504270151_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/16GeV_Pos_Pions/TB_00001534_0023_cosmc_v09_1504270157_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/16GeV_Pos_Pions/TB_00001534_0024_cosmc_v09_1504270203_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/16GeV_Pos_Pions/TB_00001534_0025_cosmc_v09_1504270209_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/16GeV_Pos_Pions/TB_00001534_0026_cosmc_v09_1504270217_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/16GeV_Pos_Pions/TB_00001534_0027_cosmc_v09_1504270223_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/16GeV_Pos_Pions/TB_00001534_0028_cosmc_v09_1504270230_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/16GeV_Pos_Pions/TB_00001534_0029_cosmc_v09_1504270237_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/16GeV_Pos_Pions/TB_00001534_0030_cosmc_v09_1504270244_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/16GeV_Pos_Pions/TB_00001534_0031_cosmc_v09_1504270250_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/16GeV_Pos_Pions/TB_00001534_0032_cosmc_v09_1504270256_camac.root",

											// 9 GeV Neg

											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0001_cosmc_v09_1504270323_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0002_cosmc_v09_1504270329_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0003_cosmc_v09_1504270335_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0004_cosmc_v09_1504270341_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0005_cosmc_v09_1504270347_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0006_cosmc_v09_1504270353_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0007_cosmc_v09_1504270359_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0008_cosmc_v09_1504270406_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0009_cosmc_v09_1504270413_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0010_cosmc_v09_1504270430_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0011_cosmc_v09_1504270441_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0012_cosmc_v09_1504270447_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0013_cosmc_v09_1504270453_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0014_cosmc_v09_1504270459_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0015_cosmc_v09_1504270506_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0016_cosmc_v09_1504270512_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0017_cosmc_v09_1504270518_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0018_cosmc_v09_1504270524_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0019_cosmc_v09_1504270530_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0020_cosmc_v09_1504270536_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0021_cosmc_v09_1504270545_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0022_cosmc_v09_1504270551_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0023_cosmc_v09_1504270557_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0024_cosmc_v09_1504270603_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0025_cosmc_v09_1504270609_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0026_cosmc_v09_1504270616_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0027_cosmc_v09_1504270622_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0028_cosmc_v09_1504270628_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0029_cosmc_v09_1504270635_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0030_cosmc_v09_1504270641_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0031_cosmc_v09_1504270647_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0032_cosmc_v09_1504270653_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0033_cosmc_v09_1504270659_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0034_cosmc_v09_1504270705_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0035_cosmc_v09_1504270711_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0036_cosmc_v09_1504270717_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0037_cosmc_v09_1504270723_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0038_cosmc_v09_1504270729_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0039_cosmc_v09_1504270735_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0040_cosmc_v09_1504270741_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0041_cosmc_v09_1504270747_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0042_cosmc_v09_1504270753_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0043_cosmc_v09_1504270759_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0044_cosmc_v09_1504270806_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0045_cosmc_v09_1504270814_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0046_cosmc_v09_1504270820_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0047_cosmc_v09_1504270826_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0048_cosmc_v09_1504270832_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0049_cosmc_v09_1504270838_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0050_cosmc_v09_1504270844_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0051_cosmc_v09_1504270851_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0052_cosmc_v09_1504270857_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0053_cosmc_v09_1504270903_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0054_cosmc_v09_1504270909_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0055_cosmc_v09_1504270915_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0056_cosmc_v09_1504270922_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0057_cosmc_v09_1504270928_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0058_cosmc_v09_1504270934_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0059_cosmc_v09_1504270940_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0060_cosmc_v09_1504270946_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0061_cosmc_v09_1504270952_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0062_cosmc_v09_1504270958_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0063_cosmc_v09_1504271005_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0064_cosmc_v09_1504271011_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/9GeV_Neg_Pions/TB_00001536_0065_cosmc_v09_1504271018_camac.root",


											// -10 GeV Neg

											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0001_cosmc_v09_1504271040_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0002_cosmc_v09_1504271046_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0003_cosmc_v09_1504271054_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0004_cosmc_v09_1504271101_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0005_cosmc_v09_1504271107_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0006_cosmc_v09_1504271115_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0007_cosmc_v09_1504271121_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0008_cosmc_v09_1504271127_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0009_cosmc_v09_1504271133_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0010_cosmc_v09_1504271140_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0011_cosmc_v09_1504271147_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0012_cosmc_v09_1504271153_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0013_cosmc_v09_1504271200_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0014_cosmc_v09_1504271206_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0015_cosmc_v09_1504271212_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0016_cosmc_v09_1504271218_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0017_cosmc_v09_1504271224_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0018_cosmc_v09_1504271230_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0019_cosmc_v09_1504271238_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0020_cosmc_v09_1504271244_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0021_cosmc_v09_1504271250_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0022_cosmc_v09_1504271256_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0023_cosmc_v09_1504271302_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0024_cosmc_v09_1504271308_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0025_cosmc_v09_1504271314_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0026_cosmc_v09_1504271334_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0027_cosmc_v09_1504271344_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0028_cosmc_v09_1504271400_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0029_cosmc_v09_1504271412_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0030_cosmc_v09_1504271419_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0031_cosmc_v09_1504271425_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0032_cosmc_v09_1504271431_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0033_cosmc_v09_1504271437_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0034_cosmc_v09_1504271443_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0035_cosmc_v09_1504271449_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0036_cosmc_v09_1504271455_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0037_cosmc_v09_1504271501_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0038_cosmc_v09_1504271507_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0039_cosmc_v09_1504271513_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0040_cosmc_v09_1504271519_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0041_cosmc_v09_1504271525_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0042_cosmc_v09_1504271531_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0043_cosmc_v09_1504271537_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0044_cosmc_v09_1504271543_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0045_cosmc_v09_1504271549_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0046_cosmc_v09_1504271556_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0047_cosmc_v09_1504271603_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0048_cosmc_v09_1504271609_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0049_cosmc_v09_1504271615_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001538_0050_cosmc_v09_1504271621_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001539_0001_cosmc_v09_1504271631_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001539_0002_cosmc_v09_1504271638_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001539_0003_cosmc_v09_1504271644_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001539_0004_cosmc_v09_1504271650_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001539_0005_cosmc_v09_1504271656_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001539_0006_cosmc_v09_1504271702_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001539_0007_cosmc_v09_1504271708_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001539_0008_cosmc_v09_1504271714_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001539_0009_cosmc_v09_1504271720_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001539_0010_cosmc_v09_1504271726_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001539_0011_cosmc_v09_1504271732_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001539_0012_cosmc_v09_1504271738_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001539_0013_cosmc_v09_1504271744_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001539_0014_cosmc_v09_1504271750_camac.root",
											"/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/Pions/10GeV_Neg_Pions/TB_00001539_0015_cosmc_v09_1504271757_camac.root"


				};

	  // ROOT files of results only with the spills

	  TString rootname_results ="RS_All_Run2_Pions.root";
	  char * name_results = rootname_results;
	  TFile f_spill(name_results,"RECREATE");
	  TTree *tree_spill = new TTree("tree_spill","Tree Spill");

	  // ========================== Defining the new the variables for the branches =================//

	  Double_t Time_spill, Time_spill_1, Time_spill_2, Time_spill_3, Time_spill_4, Time_spill_5, Time_spill_6;
	  Double_t Time_spill, Time_spill_1b, Time_spill_2b, Time_spill_3b, Time_spill_4b, Time_spill_5b, Time_spill_6b;
	  Int_t energyb, polarityb, Spill_numberb;

	  TBranch *b_Time_spill_1b = tree_spill->Branch("Time_spill_1b", &Time_spill_1b, "Time_spill_1b/D" );
	  TBranch *b_Time_spill_2b = tree_spill->Branch("Time_spill_2b", &Time_spill_2b, "Time_spill_2b/D" );
	  TBranch *b_Time_spill_3b = tree_spill->Branch("Time_spill_3b", &Time_spill_3b, "Time_spill_3b/D" );
	  TBranch *b_Time_spill_4b = tree_spill->Branch("Time_spill_4b", &Time_spill_4b, "Time_spill_4b/D" );
	  TBranch *b_Time_spill_5b = tree_spill->Branch("Time_spill_5b", &Time_spill_5b, "Time_spill_5b/D" );
	  TBranch *b_Time_spill_6b = tree_spill->Branch("Time_spill_6b", &Time_spill_6b, "Time_spill_6b/D" );

	  TBranch *b_Spill_numberb = tree_spill->Branch("Spill_numberb", &Spill_numberb, "Spill_numberb/I" );
	  TBranch *b_energyb = tree_spill->Branch("energyb", &energyb, "energyb/I" );
	  TBranch *b_polarityb = tree_spill->Branch("polarityb", &polarityb, "polarityb/I" );

	  Long64_t nentries_1, nentries_2, nentries_3, nentries_4, nentries_5, nentries_6;
	  nentries_1 = fChain->GetEntries("In_spill > 0.5 && Spill_number == 1");
	  nentries_2 = fChain->GetEntries("In_spill > 0.5 && Spill_number == 2");
	  nentries_3 = fChain->GetEntries("In_spill > 0.5 && Spill_number == 3");
	  nentries_4 = fChain->GetEntries("In_spill > 0.5 && Spill_number == 4");
	  nentries_5 = fChain->GetEntries("In_spill > 0.5 && Spill_number == 5");
	  nentries_6 = fChain->GetEntries("In_spill > 0.5 && Spill_number == 6");

	  // === Creating the ROOT file of global results ===
	  TString type ="spill_results_all_run2_pions.root";
	  char * name_file_global = type;

	  TFile f_global(name_file_global,"RECREATE");
	  TTree *spill_global     = new TTree("spill_global","Spill Global");

	  Double_t duration_spill, mi_cycle, temp ;
	  Int_t value_category ;
	  Int_t category ;
	  TBranch *b_duration_spill = spill_global->Branch("duration_spill", &duration_spill, "duration_spill/D" );
	  TBranch *b_mi_cycle = spill_global->Branch("mi_cycle", &mi_cycle, "mi_cycle/D" );
	  TBranch *b_category = spill_global->Branch("category", &category, "category/I" );
		TBranch *b_energyb = spill_global->Branch("energyb", &energyb, "energyb/I" );
	  TBranch *b_polarityb = spill_global->Branch("polarityb", &polarityb, "polarityb/I" );


    TFile *f[1000];
    TTree *tree[1000];
    Double_t t_begin[1000], porcentage ;
    cout << "Procesing ... "<< endl;


		// == 8 GeV

		  for(Int_t i=0; i<74; i++){ //For() over all the root files
			polarityb = 1;
			energyb = 8;
			cout <<  i ;

				t_begin[i]=0;
				f[i] = (TFile*)gROOT->GetListOfFiles()->FindObject(name_file[i]);

				if (!f[i] || !f[i]->IsOpen()) {
					 f[i] = new TFile(name_file[i],"READ");
				}

				f[i]->GetObject("CAMACTree",tree[i]);
		   	Init(tree[i]);      //fChain equal to the tree corresponding to the array_file_root[i]
		    cout <<  i  << "..." << endl  ;

				//  =============================== LOOP ================================= //
				//  Input: root file of TB with the most importat variable: Spill_number
				//  Loop 0 will record the begining of the time in the root file in order to remove the unix time and use only seconds
				//  Loop 1-6 will get the begining in time for each spill for future uses
				//  Loop 7 : creates the results root file with the spills but now calibrated to the begining of the spill

				// IMPORTANT Values: int jentry_array,jentry_array2,jentry_array3,jentry_array4,jentry_array5,jentry_array6;
					//
					// | ------- | ----- Spill_number == 1 ----- | ----- Spill_number == 2 ----- | ---
					//
					//
					//  A ------- B ---------------------------- C ----------------------------- D ----
					// Variables:
					// A: Time begining of the root file -> t_begin
					// B: Entry in root file for the time begining of Spill_number == 1 -> jentry_array
					// C: Entry in root file for the end begining of Spill_number == 1 -> jentry_array + nentries_1
					// This code can not know the entry for the end of the spill, but we can
					// get it by knowing the total numbers of entries.
					// D: Entry in root file for the time begining of Spill_number == X -> jentry_array_X

					int jentry_array,jentry_array2,jentry_array3,jentry_array4,jentry_array5,jentry_array6;
					Double_t Time_begin_spill_1,Time_begin_spill_2,Time_begin_spill_3,Time_begin_spill_4,Time_begin_spill_5,Time_begin_spill_6;
					Double_t t_o_spill_1, t_o_spill_2, t_o_spill_3, t_o_spill_4, t_o_spill_5, t_o_spill_6;
					Double_t exists_spill_1, exists_spill_2, exists_spill_3, exists_spill_4, exists_spill_5, exists_spill_6;

					exists_spill_1 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 1");
					//myfile3 << "Existe el spill 1?: " << exists_spill_1 << endl;
					exists_spill_2 = fChain->GetEntries("Time && In_spill>0.5  && Spill_number == 2");
					//myfile3 << "Existe el spill 2?: " <<exists_spill_2 << endl;
					exists_spill_3 = fChain->GetEntries("Time && In_spill>0.5  && Spill_number == 3");
					//myfile3 << "Existe el spill 3?: " <<exists_spill_3 << endl;
					exists_spill_4 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 4");
					//myfile3 << "Existe el spill 4?: " <<exists_spill_4 << endl;
					exists_spill_5 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 5");
					//myfile3 << "Existe el spill 5?: " <<exists_spill_5 << endl;
					exists_spill_6 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 6");
					//myfile3 << "Existe el spill 6?: " <<exists_spill_6 << endl;

					// ================= LOOP 0 : Begin of the Variable Time and =================== //

					if (fChain == 0) return; Long64_t nentries = fChain->GetEntries(); Long64_t nbytes = 0, nb = 0;
					Double_t signal1_t_begin_spill_1, signal1_t_begin_spill_2, signal1_t_begin_spill_3, signal1_t_begin_spill_4, signal1_t_begin_spill_5, signal1_t_begin_spill_6;

					signal1_t_begin_spill_1 = 0; 			signal1_t_begin_spill_2 = 0;
					signal1_t_begin_spill_3 = 0;			signal1_t_begin_spill_4 = 0;
					signal1_t_begin_spill_5 = 0;			signal1_t_begin_spill_6 = 0;

					for (Long64_t jentry=0; jentry<1;jentry++) {
							Long64_t ientry = LoadTree(jentry); if (ientry < 0) break;
							nb = fChain->GetEntry(jentry);   nbytes += nb; t_begin[i] = (Double_t) Time;
							//myfile2 << "t_begin: "<< t_begin[i] << endl;
					 }

						// ================= LOOP 1 : Begin Time for the Spill_number == 1 =================== //

					// ================= LOOP 1 : Begin Time for the Spill_number == 1 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
						 Long64_t ientry = LoadTree(jentry);                //if (ientry < 0) break;
						 nb = fChain->GetEntry(jentry);   nbytes += nb;

						 if (In_spill > 0.5 ){if (Spill_number == 1 && exists_spill_1 != 0 ){
							 //jentry_array= (Double_t) jentry;

							Time_begin_spill_1 = (Double_t) Time - t_begin[i];
							t_o_spill_1 = (Double_t) Time;
							signal1_t_begin_spill_1 = 1;
																				break ;                  }                 }             }

					// ================= LOOP 2 : Begin Time for the Spill_number == 2 =================== //

					 for (Long64_t jentry=0; jentry<nentries;jentry++) {
						 Long64_t ientry = LoadTree(jentry);                 //if (ientry < 0) break;
							nb = fChain->GetEntry(jentry);   nbytes += nb;

							if (In_spill > 0.5 ){ if (Spill_number == 2 ){ jentry_array2= (Double_t) jentry;
								Time_begin_spill_2 = (Double_t) Time - t_begin[i];
								t_o_spill_2 = (Double_t) Time;
								////myfile << "jentry_array2: "<< jentry_array2 << endl;
								 //myfile2 << "Time_spill_2 "<< Time_begin_spill_2 << endl;
								 signal1_t_begin_spill_2 = 1;
										break ;                    }                  }              }

					// ================= LOOP 3 : Begin Time for the Spill_number == 3 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
							 Long64_t ientry = LoadTree(jentry);                 //if (ientry < 0) break;
							 nb = fChain->GetEntry(jentry);   nbytes += nb;

							 if (In_spill > 0.5 ){if (Spill_number == 3 ){jentry_array3= (Double_t) jentry;
								Time_begin_spill_3 = (Double_t) Time - t_begin[i];
								t_o_spill_3 = (Double_t) Time;
								 ////myfile << "jentry_array3: "<< jentry_array3 << endl;
								 //myfile2 << "Time_spill_3 "<< Time_begin_spill_3 << endl;
								 signal1_t_begin_spill_3 = 1;
										 break ;                     }                   }               }

					// ================= LOOP 4 : Begin Time for the Spill_number == 4 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
								Long64_t ientry = LoadTree(jentry);
								// if (ientry < 0) break;
								nb = fChain->GetEntry(jentry);   nbytes += nb;

								if (In_spill > 0.5 ){if (Spill_number == 4 ){jentry_array4= (Double_t) jentry;
								Time_begin_spill_4 = (Double_t) Time - t_begin[i];
								t_o_spill_4 = (Double_t) Time;
								 ////myfile << "jentry_array4: "<< jentry_array4 << endl;
								 //myfile2 << "Time_spill_4 "<< Time_begin_spill_4 << endl;
								 signal1_t_begin_spill_4 = 1;
											break ;                      }                    }                }

					// ================= LOOP 5 : Begin Time for the Spill_number == 5 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
								 Long64_t ientry = LoadTree(jentry);
								 //if (ientry < 0) break;
								 nb = fChain->GetEntry(jentry);   nbytes += nb;

								 if (In_spill > 0.5 ){if (Spill_number == 5 ){jentry_array5= (Double_t) jentry;
								Time_begin_spill_5 = (Double_t) Time - t_begin[i];
								t_o_spill_5 = (Double_t) Time;
								 ////myfile << "jentry_array5: "<< jentry_array5 << endl;
								 //myfile2 << "Time_spill_5 "<< Time_begin_spill_5 << endl;
								 signal1_t_begin_spill_5 = 1;
											 break ;                       }                     }                 }

					// ================= LOOP 6 : Begin Time for the Spill_number == 2 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
									Long64_t ientry = LoadTree(jentry);
									//if (ientry < 0) break;
									nb = fChain->GetEntry(jentry);   nbytes += nb;

									if (In_spill > 0.5 ){if (Spill_number == 6 ){jentry_array6= (Double_t) jentry;
								Time_begin_spill_6 = (Double_t) Time - t_begin[i];
								t_o_spill_6 = (Double_t) Time;
								 ////myfile << "jentry_array6: "<< jentry_array6 << endl;
								 //myfile2 << "Time_spill_6 "<< Time_begin_spill_6 << endl;
								 signal1_t_begin_spill_6 = 1;
												break ;                        }                      }                  }

					Float_t interval_between_spills = 0.0;

					if (fChain == 0) return;
					 Long64_t nentries = fChain->GetEntries();
					 Long64_t nbytes = 0, nb = 0;

					 Double_t duration_spill_1, duration_spill_2, duration_spill_3, duration_spill_4, duration_spill_5, duration_spill_6;

					 for (Long64_t jentry=0; jentry<nentries;jentry++) {
						 Long64_t ientry = LoadTree(jentry);
						 //if (ientry < 0) break;
						 nb = fChain->GetEntry(jentry);   nbytes += nb;

							//Conditions for Spill has actual values

							Time_spill_1b = -1; Time_spill_2b = -1; Time_spill_3b = -1;
							Time_spill_4b = -1; Time_spill_5b = -1; Time_spill_6b = -1;
							mi_cycle = 0;

		      	if (In_spill > 0.5 )              {
		          if (Spill_number == 1  )                 {

		                  Time_spill_1 = (Double_t) Time -t_begin[i];
		                  duration_spill_1 = Time_spill_1 - Time_begin_spill_1;

		                  Time_spill_1b = (Double_t) Time - t_o_spill_1;
		                  Spill_numberb = 1;
		                  tree_spill->Fill();


		            }
		            else if (Spill_number == 2 )
		            {
		                  Time_spill_2= (Double_t) Time -t_begin[i];
		                  duration_spill_2 = Time_spill_2 - Time_begin_spill_2;


		                  Time_spill_2b = (Double_t) Time - t_o_spill_2;
		                  Spill_numberb = 2;
		                  tree_spill->Fill();

		            }

		            else if (Spill_number == 3  )
		            {
		                  Time_spill_3= (Double_t) Time -t_begin[i];
		                  duration_spill_3 = Time_spill_3 - Time_begin_spill_3;

		                  Time_spill_3b = (Double_t) Time - t_o_spill_3;
		                  Spill_numberb = 3;
		                  tree_spill->Fill();

		             }

		           else if (Spill_number == 4  )
		           {
		                 Time_spill_4= (Double_t) Time -t_begin[i];
		                 duration_spill_4 = Time_spill_4 - Time_begin_spill_4;


		                 Time_spill_4b = (Double_t) Time - t_o_spill_4 ;
		                 Spill_numberb = 4;
		                 tree_spill->Fill();
		          	}

		          	else if (Spill_number == 5  )
		          	{
		                Time_spill_5= (Double_t) Time -t_begin[i];
		                duration_spill_5 = Time_spill_5 - Time_begin_spill_5;


		                Time_spill_5b = (Double_t) Time - t_o_spill_5 ;
		                Spill_numberb = 5;
		                tree_spill->Fill();
		          	}

		         	 else if (Spill_number == 6  )
		         	 {
		               Time_spill_6= (Double_t) Time -t_begin[i];
		               duration_spill_6 = Time_spill_6 - Time_begin_spill_6;


		               Time_spill_6b = (Double_t) Time - t_o_spill_6;
		               Spill_numberb = 6;
		               tree_spill->Fill();
		         	 }

		        } // end of:  if (In_spill > 0.5 )
		 			}//end of: for (Long64_t jentry=0; jentry<nentries;jentry++)

					  	// ## 1

						  duration_spill =  duration_spill_1;
						  category = 1;
						  mi_cycle = 0;
							//myfile << mi_cycle << endl;
							//myfile4 << duration_spill << endl;
						  spill_global->Fill();

							// ## 2

							if(signal1_t_begin_spill_1 == 1 && signal1_t_begin_spill_2 == 1){

								  duration_spill =  duration_spill_2;
								  mi_cycle = t_o_spill_2 - t_o_spill_1;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

								  duration_spill =  duration_spill_2;
								  mi_cycle = 0;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							// ## 3

							if(signal1_t_begin_spill_3 == 1 && signal1_t_begin_spill_2 == 1){

								  duration_spill =  duration_spill_3;
								  mi_cycle = t_o_spill_3 - t_o_spill_2;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

								  duration_spill =  duration_spill_3;
								  mi_cycle = 0;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}

						  // ## 4
							if(signal1_t_begin_spill_3 == 1 && signal1_t_begin_spill_4 == 1){

								  duration_spill =  duration_spill_4;
								  mi_cycle =  t_o_spill_4 - t_o_spill_3;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

									duration_spill =  duration_spill_4;
								  mi_cycle = 0;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
						  // ## 5

							if(signal1_t_begin_spill_4 == 1 && signal1_t_begin_spill_5 == 1){

								  duration_spill =  duration_spill_5;
								  mi_cycle = t_o_spill_5 - t_o_spill_4;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

							  duration_spill =  duration_spill_5;
							  mi_cycle = 0 ;
							  category = 1;
							  //myfile << mi_cycle << endl;
								//myfile4 << duration_spill << endl;
							  spill_global->Fill();

							}
						  // ## 6

							if(signal1_t_begin_spill_6 == 1 && signal1_t_begin_spill_5 == 1){

							  duration_spill =  duration_spill_6;
							  mi_cycle = t_o_spill_6 - t_o_spill_5;
							  category = 1;
							  //myfile << mi_cycle << endl;
								//myfile4 << duration_spill << endl;
							  spill_global->Fill();

							}
							else {

							  duration_spill =  duration_spill_6;
							  mi_cycle = 0;
							  category = 1;
							  //myfile << mi_cycle << endl;
								//myfile4 << duration_spill << endl;
							  spill_global->Fill();

							}


		}  // End For the ROOT files 8GeV

		// == 6 GeV

		  for(Int_t i=74; i<74+71; i++){ //For() over all the root files
			polarityb = 1;
			energyb = 6;
			cout <<  i ;

				t_begin[i]=0;
				f[i] = (TFile*)gROOT->GetListOfFiles()->FindObject(name_file[i]);

				if (!f[i] || !f[i]->IsOpen()) {
					 f[i] = new TFile(name_file[i],"READ");
				}

				f[i]->GetObject("CAMACTree",tree[i]);
		   	Init(tree[i]);      //fChain equal to the tree corresponding to the array_file_root[i]
		    cout <<  i  << "..." << endl  ;

				//  =============================== LOOP ================================= //
				//  Input: root file of TB with the most importat variable: Spill_number
				//  Loop 0 will record the begining of the time in the root file in order to remove the unix time and use only seconds
				//  Loop 1-6 will get the begining in time for each spill for future uses
				//  Loop 7 : creates the results root file with the spills but now calibrated to the begining of the spill

				// IMPORTANT Values: int jentry_array,jentry_array2,jentry_array3,jentry_array4,jentry_array5,jentry_array6;
					//
					// | ------- | ----- Spill_number == 1 ----- | ----- Spill_number == 2 ----- | ---
					//
					//
					//  A ------- B ---------------------------- C ----------------------------- D ----
					// Variables:
					// A: Time begining of the root file -> t_begin
					// B: Entry in root file for the time begining of Spill_number == 1 -> jentry_array
					// C: Entry in root file for the end begining of Spill_number == 1 -> jentry_array + nentries_1
					// This code can not know the entry for the end of the spill, but we can
					// get it by knowing the total numbers of entries.
					// D: Entry in root file for the time begining of Spill_number == X -> jentry_array_X

					int jentry_array,jentry_array2,jentry_array3,jentry_array4,jentry_array5,jentry_array6;
					Double_t Time_begin_spill_1,Time_begin_spill_2,Time_begin_spill_3,Time_begin_spill_4,Time_begin_spill_5,Time_begin_spill_6;
					Double_t t_o_spill_1, t_o_spill_2, t_o_spill_3, t_o_spill_4, t_o_spill_5, t_o_spill_6;
					Double_t exists_spill_1, exists_spill_2, exists_spill_3, exists_spill_4, exists_spill_5, exists_spill_6;

					exists_spill_1 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 1");
					//myfile3 << "Existe el spill 1?: " << exists_spill_1 << endl;
					exists_spill_2 = fChain->GetEntries("Time && In_spill>0.5  && Spill_number == 2");
					//myfile3 << "Existe el spill 2?: " <<exists_spill_2 << endl;
					exists_spill_3 = fChain->GetEntries("Time && In_spill>0.5  && Spill_number == 3");
					//myfile3 << "Existe el spill 3?: " <<exists_spill_3 << endl;
					exists_spill_4 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 4");
					//myfile3 << "Existe el spill 4?: " <<exists_spill_4 << endl;
					exists_spill_5 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 5");
					//myfile3 << "Existe el spill 5?: " <<exists_spill_5 << endl;
					exists_spill_6 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 6");
					//myfile3 << "Existe el spill 6?: " <<exists_spill_6 << endl;

					// ================= LOOP 0 : Begin of the Variable Time and =================== //

					if (fChain == 0) return; Long64_t nentries = fChain->GetEntries(); Long64_t nbytes = 0, nb = 0;
					Double_t signal1_t_begin_spill_1, signal1_t_begin_spill_2, signal1_t_begin_spill_3, signal1_t_begin_spill_4, signal1_t_begin_spill_5, signal1_t_begin_spill_6;

					signal1_t_begin_spill_1 = 0; 			signal1_t_begin_spill_2 = 0;
					signal1_t_begin_spill_3 = 0;			signal1_t_begin_spill_4 = 0;
					signal1_t_begin_spill_5 = 0;			signal1_t_begin_spill_6 = 0;

					for (Long64_t jentry=0; jentry<1;jentry++) {
							Long64_t ientry = LoadTree(jentry); if (ientry < 0) break;
							nb = fChain->GetEntry(jentry);   nbytes += nb; t_begin[i] = (Double_t) Time;
							//myfile2 << "t_begin: "<< t_begin[i] << endl;
					 }

						// ================= LOOP 1 : Begin Time for the Spill_number == 1 =================== //

					// ================= LOOP 1 : Begin Time for the Spill_number == 1 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
						 Long64_t ientry = LoadTree(jentry);                //if (ientry < 0) break;
						 nb = fChain->GetEntry(jentry);   nbytes += nb;

						 if (In_spill > 0.5 ){if (Spill_number == 1 && exists_spill_1 != 0 ){
							 //jentry_array= (Double_t) jentry;

							Time_begin_spill_1 = (Double_t) Time - t_begin[i];
							t_o_spill_1 = (Double_t) Time;
							signal1_t_begin_spill_1 = 1;
																				break ;                  }                 }             }

					// ================= LOOP 2 : Begin Time for the Spill_number == 2 =================== //

					 for (Long64_t jentry=0; jentry<nentries;jentry++) {
						 Long64_t ientry = LoadTree(jentry);                 //if (ientry < 0) break;
							nb = fChain->GetEntry(jentry);   nbytes += nb;

							if (In_spill > 0.5 ){ if (Spill_number == 2 ){ jentry_array2= (Double_t) jentry;
								Time_begin_spill_2 = (Double_t) Time - t_begin[i];
								t_o_spill_2 = (Double_t) Time;
								////myfile << "jentry_array2: "<< jentry_array2 << endl;
								 //myfile2 << "Time_spill_2 "<< Time_begin_spill_2 << endl;
								 signal1_t_begin_spill_2 = 1;
										break ;                    }                  }              }

					// ================= LOOP 3 : Begin Time for the Spill_number == 3 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
							 Long64_t ientry = LoadTree(jentry);                 //if (ientry < 0) break;
							 nb = fChain->GetEntry(jentry);   nbytes += nb;

							 if (In_spill > 0.5 ){if (Spill_number == 3 ){jentry_array3= (Double_t) jentry;
								Time_begin_spill_3 = (Double_t) Time - t_begin[i];
								t_o_spill_3 = (Double_t) Time;
								 ////myfile << "jentry_array3: "<< jentry_array3 << endl;
								 //myfile2 << "Time_spill_3 "<< Time_begin_spill_3 << endl;
								 signal1_t_begin_spill_3 = 1;
										 break ;                     }                   }               }

					// ================= LOOP 4 : Begin Time for the Spill_number == 4 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
								Long64_t ientry = LoadTree(jentry);
								// if (ientry < 0) break;
								nb = fChain->GetEntry(jentry);   nbytes += nb;

								if (In_spill > 0.5 ){if (Spill_number == 4 ){jentry_array4= (Double_t) jentry;
								Time_begin_spill_4 = (Double_t) Time - t_begin[i];
								t_o_spill_4 = (Double_t) Time;
								 ////myfile << "jentry_array4: "<< jentry_array4 << endl;
								 //myfile2 << "Time_spill_4 "<< Time_begin_spill_4 << endl;
								 signal1_t_begin_spill_4 = 1;
											break ;                      }                    }                }

					// ================= LOOP 5 : Begin Time for the Spill_number == 5 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
								 Long64_t ientry = LoadTree(jentry);
								 //if (ientry < 0) break;
								 nb = fChain->GetEntry(jentry);   nbytes += nb;

								 if (In_spill > 0.5 ){if (Spill_number == 5 ){jentry_array5= (Double_t) jentry;
								Time_begin_spill_5 = (Double_t) Time - t_begin[i];
								t_o_spill_5 = (Double_t) Time;
								 ////myfile << "jentry_array5: "<< jentry_array5 << endl;
								 //myfile2 << "Time_spill_5 "<< Time_begin_spill_5 << endl;
								 signal1_t_begin_spill_5 = 1;
											 break ;                       }                     }                 }

					// ================= LOOP 6 : Begin Time for the Spill_number == 2 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
									Long64_t ientry = LoadTree(jentry);
									//if (ientry < 0) break;
									nb = fChain->GetEntry(jentry);   nbytes += nb;

									if (In_spill > 0.5 ){if (Spill_number == 6 ){jentry_array6= (Double_t) jentry;
								Time_begin_spill_6 = (Double_t) Time - t_begin[i];
								t_o_spill_6 = (Double_t) Time;
								 ////myfile << "jentry_array6: "<< jentry_array6 << endl;
								 //myfile2 << "Time_spill_6 "<< Time_begin_spill_6 << endl;
								 signal1_t_begin_spill_6 = 1;
												break ;                        }                      }                  }

					Float_t interval_between_spills = 0.0;

					if (fChain == 0) return;
					 Long64_t nentries = fChain->GetEntries();
					 Long64_t nbytes = 0, nb = 0;

					 Double_t duration_spill_1, duration_spill_2, duration_spill_3, duration_spill_4, duration_spill_5, duration_spill_6;

					 for (Long64_t jentry=0; jentry<nentries;jentry++) {
						 Long64_t ientry = LoadTree(jentry);
						 //if (ientry < 0) break;
						 nb = fChain->GetEntry(jentry);   nbytes += nb;

							//Conditions for Spill has actual values

							Time_spill_1b = -1; Time_spill_2b = -1; Time_spill_3b = -1;
							Time_spill_4b = -1; Time_spill_5b = -1; Time_spill_6b = -1;
							mi_cycle = 0;

		      	if (In_spill > 0.5 )              {
		          if (Spill_number == 1  )                 {

		                  Time_spill_1 = (Double_t) Time -t_begin[i];
		                  duration_spill_1 = Time_spill_1 - Time_begin_spill_1;

		                  Time_spill_1b = (Double_t) Time - t_o_spill_1;
		                  Spill_numberb = 1;
		                  tree_spill->Fill();


		            }
		            else if (Spill_number == 2 )
		            {
		                  Time_spill_2= (Double_t) Time -t_begin[i];
		                  duration_spill_2 = Time_spill_2 - Time_begin_spill_2;


		                  Time_spill_2b = (Double_t) Time - t_o_spill_2;
		                  Spill_numberb = 2;
		                  tree_spill->Fill();

		            }

		            else if (Spill_number == 3  )
		            {
		                  Time_spill_3= (Double_t) Time -t_begin[i];
		                  duration_spill_3 = Time_spill_3 - Time_begin_spill_3;

		                  Time_spill_3b = (Double_t) Time - t_o_spill_3;
		                  Spill_numberb = 3;
		                  tree_spill->Fill();

		             }

		           else if (Spill_number == 4  )
		           {
		                 Time_spill_4= (Double_t) Time -t_begin[i];
		                 duration_spill_4 = Time_spill_4 - Time_begin_spill_4;


		                 Time_spill_4b = (Double_t) Time - t_o_spill_4 ;
		                 Spill_numberb = 4;
		                 tree_spill->Fill();
		          	}

		          	else if (Spill_number == 5  )
		          	{
		                Time_spill_5= (Double_t) Time -t_begin[i];
		                duration_spill_5 = Time_spill_5 - Time_begin_spill_5;


		                Time_spill_5b = (Double_t) Time - t_o_spill_5 ;
		                Spill_numberb = 5;
		                tree_spill->Fill();
		          	}

		         	 else if (Spill_number == 6  )
		         	 {
		               Time_spill_6= (Double_t) Time -t_begin[i];
		               duration_spill_6 = Time_spill_6 - Time_begin_spill_6;


		               Time_spill_6b = (Double_t) Time - t_o_spill_6;
		               Spill_numberb = 6;
		               tree_spill->Fill();
		         	 }

		        } // end of:  if (In_spill > 0.5 )
		 			}//end of: for (Long64_t jentry=0; jentry<nentries;jentry++)

					  	// ## 1

						  duration_spill =  duration_spill_1;
						  category = 1;
						  mi_cycle = 0;
							//myfile << mi_cycle << endl;
							//myfile4 << duration_spill << endl;
						  spill_global->Fill();

							// ## 2

							if(signal1_t_begin_spill_1 == 1 && signal1_t_begin_spill_2 == 1){

								  duration_spill =  duration_spill_2;
								  mi_cycle = t_o_spill_2 - t_o_spill_1;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

								  duration_spill =  duration_spill_2;
								  mi_cycle = 0;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							// ## 3

							if(signal1_t_begin_spill_3 == 1 && signal1_t_begin_spill_2 == 1){

								  duration_spill =  duration_spill_3;
								  mi_cycle = t_o_spill_3 - t_o_spill_2;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

								  duration_spill =  duration_spill_3;
								  mi_cycle = 0;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}

						  // ## 4
							if(signal1_t_begin_spill_3 == 1 && signal1_t_begin_spill_4 == 1){

								  duration_spill =  duration_spill_4;
								  mi_cycle =  t_o_spill_4 - t_o_spill_3;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

									duration_spill =  duration_spill_4;
								  mi_cycle = 0;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
						  // ## 5

							if(signal1_t_begin_spill_4 == 1 && signal1_t_begin_spill_5 == 1){

								  duration_spill =  duration_spill_5;
								  mi_cycle = t_o_spill_5 - t_o_spill_4;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

							  duration_spill =  duration_spill_5;
							  mi_cycle = 0 ;
							  category = 1;
							  //myfile << mi_cycle << endl;
								//myfile4 << duration_spill << endl;
							  spill_global->Fill();

							}
						  // ## 6

							if(signal1_t_begin_spill_6 == 1 && signal1_t_begin_spill_5 == 1){

							  duration_spill =  duration_spill_6;
							  mi_cycle = t_o_spill_6 - t_o_spill_5;
							  category = 1;
							  //myfile << mi_cycle << endl;
								//myfile4 << duration_spill << endl;
							  spill_global->Fill();

							}
							else {

							  duration_spill =  duration_spill_6;
							  mi_cycle = 0;
							  category = 1;
							  //myfile << mi_cycle << endl;
								//myfile4 << duration_spill << endl;
							  spill_global->Fill();

							}


		}  // End For the ROOT files 6GeV


		// == 4 GeV

		  for(Int_t i=74+71; i<74+71+74; i++){ //For() over all the root files
			polarityb = 1;
			energyb = 4;
			cout <<  i ;

				t_begin[i]=0;
				f[i] = (TFile*)gROOT->GetListOfFiles()->FindObject(name_file[i]);

				if (!f[i] || !f[i]->IsOpen()) {
					 f[i] = new TFile(name_file[i],"READ");
				}

				f[i]->GetObject("CAMACTree",tree[i]);
		   	Init(tree[i]);      //fChain equal to the tree corresponding to the array_file_root[i]
		    cout <<  i  << "..." << endl  ;

				//  =============================== LOOP ================================= //
				//  Input: root file of TB with the most importat variable: Spill_number
				//  Loop 0 will record the begining of the time in the root file in order to remove the unix time and use only seconds
				//  Loop 1-6 will get the begining in time for each spill for future uses
				//  Loop 7 : creates the results root file with the spills but now calibrated to the begining of the spill

				// IMPORTANT Values: int jentry_array,jentry_array2,jentry_array3,jentry_array4,jentry_array5,jentry_array6;
					//
					// | ------- | ----- Spill_number == 1 ----- | ----- Spill_number == 2 ----- | ---
					//
					//
					//  A ------- B ---------------------------- C ----------------------------- D ----
					// Variables:
					// A: Time begining of the root file -> t_begin
					// B: Entry in root file for the time begining of Spill_number == 1 -> jentry_array
					// C: Entry in root file for the end begining of Spill_number == 1 -> jentry_array + nentries_1
					// This code can not know the entry for the end of the spill, but we can
					// get it by knowing the total numbers of entries.
					// D: Entry in root file for the time begining of Spill_number == X -> jentry_array_X

					int jentry_array,jentry_array2,jentry_array3,jentry_array4,jentry_array5,jentry_array6;
					Double_t Time_begin_spill_1,Time_begin_spill_2,Time_begin_spill_3,Time_begin_spill_4,Time_begin_spill_5,Time_begin_spill_6;
					Double_t t_o_spill_1, t_o_spill_2, t_o_spill_3, t_o_spill_4, t_o_spill_5, t_o_spill_6;
					Double_t exists_spill_1, exists_spill_2, exists_spill_3, exists_spill_4, exists_spill_5, exists_spill_6;

					exists_spill_1 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 1");
					//myfile3 << "Existe el spill 1?: " << exists_spill_1 << endl;
					exists_spill_2 = fChain->GetEntries("Time && In_spill>0.5  && Spill_number == 2");
					//myfile3 << "Existe el spill 2?: " <<exists_spill_2 << endl;
					exists_spill_3 = fChain->GetEntries("Time && In_spill>0.5  && Spill_number == 3");
					//myfile3 << "Existe el spill 3?: " <<exists_spill_3 << endl;
					exists_spill_4 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 4");
					//myfile3 << "Existe el spill 4?: " <<exists_spill_4 << endl;
					exists_spill_5 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 5");
					//myfile3 << "Existe el spill 5?: " <<exists_spill_5 << endl;
					exists_spill_6 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 6");
					//myfile3 << "Existe el spill 6?: " <<exists_spill_6 << endl;

					// ================= LOOP 0 : Begin of the Variable Time and =================== //

					if (fChain == 0) return; Long64_t nentries = fChain->GetEntries(); Long64_t nbytes = 0, nb = 0;
					Double_t signal1_t_begin_spill_1, signal1_t_begin_spill_2, signal1_t_begin_spill_3, signal1_t_begin_spill_4, signal1_t_begin_spill_5, signal1_t_begin_spill_6;

					signal1_t_begin_spill_1 = 0; 			signal1_t_begin_spill_2 = 0;
					signal1_t_begin_spill_3 = 0;			signal1_t_begin_spill_4 = 0;
					signal1_t_begin_spill_5 = 0;			signal1_t_begin_spill_6 = 0;

					for (Long64_t jentry=0; jentry<1;jentry++) {
							Long64_t ientry = LoadTree(jentry); if (ientry < 0) break;
							nb = fChain->GetEntry(jentry);   nbytes += nb; t_begin[i] = (Double_t) Time;
							//myfile2 << "t_begin: "<< t_begin[i] << endl;
					 }

						// ================= LOOP 1 : Begin Time for the Spill_number == 1 =================== //

					// ================= LOOP 1 : Begin Time for the Spill_number == 1 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
						 Long64_t ientry = LoadTree(jentry);                //if (ientry < 0) break;
						 nb = fChain->GetEntry(jentry);   nbytes += nb;

						 if (In_spill > 0.5 ){if (Spill_number == 1 && exists_spill_1 != 0 ){
							 //jentry_array= (Double_t) jentry;

							Time_begin_spill_1 = (Double_t) Time - t_begin[i];
							t_o_spill_1 = (Double_t) Time;
							signal1_t_begin_spill_1 = 1;
																				break ;                  }                 }             }

					// ================= LOOP 2 : Begin Time for the Spill_number == 2 =================== //

					 for (Long64_t jentry=0; jentry<nentries;jentry++) {
						 Long64_t ientry = LoadTree(jentry);                 //if (ientry < 0) break;
							nb = fChain->GetEntry(jentry);   nbytes += nb;

							if (In_spill > 0.5 ){ if (Spill_number == 2 ){ jentry_array2= (Double_t) jentry;
								Time_begin_spill_2 = (Double_t) Time - t_begin[i];
								t_o_spill_2 = (Double_t) Time;
								////myfile << "jentry_array2: "<< jentry_array2 << endl;
								 //myfile2 << "Time_spill_2 "<< Time_begin_spill_2 << endl;
								 signal1_t_begin_spill_2 = 1;
										break ;                    }                  }              }

					// ================= LOOP 3 : Begin Time for the Spill_number == 3 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
							 Long64_t ientry = LoadTree(jentry);                 //if (ientry < 0) break;
							 nb = fChain->GetEntry(jentry);   nbytes += nb;

							 if (In_spill > 0.5 ){if (Spill_number == 3 ){jentry_array3= (Double_t) jentry;
								Time_begin_spill_3 = (Double_t) Time - t_begin[i];
								t_o_spill_3 = (Double_t) Time;
								 ////myfile << "jentry_array3: "<< jentry_array3 << endl;
								 //myfile2 << "Time_spill_3 "<< Time_begin_spill_3 << endl;
								 signal1_t_begin_spill_3 = 1;
										 break ;                     }                   }               }

					// ================= LOOP 4 : Begin Time for the Spill_number == 4 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
								Long64_t ientry = LoadTree(jentry);
								// if (ientry < 0) break;
								nb = fChain->GetEntry(jentry);   nbytes += nb;

								if (In_spill > 0.5 ){if (Spill_number == 4 ){jentry_array4= (Double_t) jentry;
								Time_begin_spill_4 = (Double_t) Time - t_begin[i];
								t_o_spill_4 = (Double_t) Time;
								 ////myfile << "jentry_array4: "<< jentry_array4 << endl;
								 //myfile2 << "Time_spill_4 "<< Time_begin_spill_4 << endl;
								 signal1_t_begin_spill_4 = 1;
											break ;                      }                    }                }

					// ================= LOOP 5 : Begin Time for the Spill_number == 5 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
								 Long64_t ientry = LoadTree(jentry);
								 //if (ientry < 0) break;
								 nb = fChain->GetEntry(jentry);   nbytes += nb;

								 if (In_spill > 0.5 ){if (Spill_number == 5 ){jentry_array5= (Double_t) jentry;
								Time_begin_spill_5 = (Double_t) Time - t_begin[i];
								t_o_spill_5 = (Double_t) Time;
								 ////myfile << "jentry_array5: "<< jentry_array5 << endl;
								 //myfile2 << "Time_spill_5 "<< Time_begin_spill_5 << endl;
								 signal1_t_begin_spill_5 = 1;
											 break ;                       }                     }                 }

					// ================= LOOP 6 : Begin Time for the Spill_number == 2 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
									Long64_t ientry = LoadTree(jentry);
									//if (ientry < 0) break;
									nb = fChain->GetEntry(jentry);   nbytes += nb;

									if (In_spill > 0.5 ){if (Spill_number == 6 ){jentry_array6= (Double_t) jentry;
								Time_begin_spill_6 = (Double_t) Time - t_begin[i];
								t_o_spill_6 = (Double_t) Time;
								 ////myfile << "jentry_array6: "<< jentry_array6 << endl;
								 //myfile2 << "Time_spill_6 "<< Time_begin_spill_6 << endl;
								 signal1_t_begin_spill_6 = 1;
												break ;                        }                      }                  }

					Float_t interval_between_spills = 0.0;

					if (fChain == 0) return;
					 Long64_t nentries = fChain->GetEntries();
					 Long64_t nbytes = 0, nb = 0;

					 Double_t duration_spill_1, duration_spill_2, duration_spill_3, duration_spill_4, duration_spill_5, duration_spill_6;

					 for (Long64_t jentry=0; jentry<nentries;jentry++) {
						 Long64_t ientry = LoadTree(jentry);
						 //if (ientry < 0) break;
						 nb = fChain->GetEntry(jentry);   nbytes += nb;

							//Conditions for Spill has actual values

							Time_spill_1b = -1; Time_spill_2b = -1; Time_spill_3b = -1;
							Time_spill_4b = -1; Time_spill_5b = -1; Time_spill_6b = -1;
							mi_cycle = 0;

		      	if (In_spill > 0.5 )              {
		          if (Spill_number == 1  )                 {

		                  Time_spill_1 = (Double_t) Time -t_begin[i];
		                  duration_spill_1 = Time_spill_1 - Time_begin_spill_1;

		                  Time_spill_1b = (Double_t) Time - t_o_spill_1;
		                  Spill_numberb = 1;
		                  tree_spill->Fill();


		            }
		            else if (Spill_number == 2 )
		            {
		                  Time_spill_2= (Double_t) Time -t_begin[i];
		                  duration_spill_2 = Time_spill_2 - Time_begin_spill_2;


		                  Time_spill_2b = (Double_t) Time - t_o_spill_2;
		                  Spill_numberb = 2;
		                  tree_spill->Fill();

		            }

		            else if (Spill_number == 3  )
		            {
		                  Time_spill_3= (Double_t) Time -t_begin[i];
		                  duration_spill_3 = Time_spill_3 - Time_begin_spill_3;

		                  Time_spill_3b = (Double_t) Time - t_o_spill_3;
		                  Spill_numberb = 3;
		                  tree_spill->Fill();

		             }

		           else if (Spill_number == 4  )
		           {
		                 Time_spill_4= (Double_t) Time -t_begin[i];
		                 duration_spill_4 = Time_spill_4 - Time_begin_spill_4;


		                 Time_spill_4b = (Double_t) Time - t_o_spill_4 ;
		                 Spill_numberb = 4;
		                 tree_spill->Fill();
		          	}

		          	else if (Spill_number == 5  )
		          	{
		                Time_spill_5= (Double_t) Time -t_begin[i];
		                duration_spill_5 = Time_spill_5 - Time_begin_spill_5;


		                Time_spill_5b = (Double_t) Time - t_o_spill_5 ;
		                Spill_numberb = 5;
		                tree_spill->Fill();
		          	}

		         	 else if (Spill_number == 6  )
		         	 {
		               Time_spill_6= (Double_t) Time -t_begin[i];
		               duration_spill_6 = Time_spill_6 - Time_begin_spill_6;


		               Time_spill_6b = (Double_t) Time - t_o_spill_6;
		               Spill_numberb = 6;
		               tree_spill->Fill();
		         	 }

		        } // end of:  if (In_spill > 0.5 )
		 			}//end of: for (Long64_t jentry=0; jentry<nentries;jentry++)

					  	// ## 1

						  duration_spill =  duration_spill_1;
						  category = 1;
						  mi_cycle = 0;
							//myfile << mi_cycle << endl;
							//myfile4 << duration_spill << endl;
						  spill_global->Fill();

							// ## 2

							if(signal1_t_begin_spill_1 == 1 && signal1_t_begin_spill_2 == 1){

								  duration_spill =  duration_spill_2;
								  mi_cycle = t_o_spill_2 - t_o_spill_1;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

								  duration_spill =  duration_spill_2;
								  mi_cycle = 0;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							// ## 3

							if(signal1_t_begin_spill_3 == 1 && signal1_t_begin_spill_2 == 1){

								  duration_spill =  duration_spill_3;
								  mi_cycle = t_o_spill_3 - t_o_spill_2;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

								  duration_spill =  duration_spill_3;
								  mi_cycle = 0;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}

						  // ## 4
							if(signal1_t_begin_spill_3 == 1 && signal1_t_begin_spill_4 == 1){

								  duration_spill =  duration_spill_4;
								  mi_cycle =  t_o_spill_4 - t_o_spill_3;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

									duration_spill =  duration_spill_4;
								  mi_cycle = 0;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
						  // ## 5

							if(signal1_t_begin_spill_4 == 1 && signal1_t_begin_spill_5 == 1){

								  duration_spill =  duration_spill_5;
								  mi_cycle = t_o_spill_5 - t_o_spill_4;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

							  duration_spill =  duration_spill_5;
							  mi_cycle = 0 ;
							  category = 1;
							  //myfile << mi_cycle << endl;
								//myfile4 << duration_spill << endl;
							  spill_global->Fill();

							}
						  // ## 6

							if(signal1_t_begin_spill_6 == 1 && signal1_t_begin_spill_5 == 1){

							  duration_spill =  duration_spill_6;
							  mi_cycle = t_o_spill_6 - t_o_spill_5;
							  category = 1;
							  //myfile << mi_cycle << endl;
								//myfile4 << duration_spill << endl;
							  spill_global->Fill();

							}
							else {

							  duration_spill =  duration_spill_6;
							  mi_cycle = 0;
							  category = 1;
							  //myfile << mi_cycle << endl;
								//myfile4 << duration_spill << endl;
							  spill_global->Fill();

							}


		}  // End For the ROOT files 4GeV

		// == 8 GeV Neg

		  for(Int_t i=74+71+74; i<74+71+74+68; i++){ //For() over all the root files
			polarityb = -1;
			energyb = 8;
			cout <<  i ;

				t_begin[i]=0;
				f[i] = (TFile*)gROOT->GetListOfFiles()->FindObject(name_file[i]);

				if (!f[i] || !f[i]->IsOpen()) {
					 f[i] = new TFile(name_file[i],"READ");
				}

				f[i]->GetObject("CAMACTree",tree[i]);
		   	Init(tree[i]);      //fChain equal to the tree corresponding to the array_file_root[i]
		    cout <<  i  << "..." << endl  ;

				//  =============================== LOOP ================================= //
				//  Input: root file of TB with the most importat variable: Spill_number
				//  Loop 0 will record the begining of the time in the root file in order to remove the unix time and use only seconds
				//  Loop 1-6 will get the begining in time for each spill for future uses
				//  Loop 7 : creates the results root file with the spills but now calibrated to the begining of the spill

				// IMPORTANT Values: int jentry_array,jentry_array2,jentry_array3,jentry_array4,jentry_array5,jentry_array6;
					//
					// | ------- | ----- Spill_number == 1 ----- | ----- Spill_number == 2 ----- | ---
					//
					//
					//  A ------- B ---------------------------- C ----------------------------- D ----
					// Variables:
					// A: Time begining of the root file -> t_begin
					// B: Entry in root file for the time begining of Spill_number == 1 -> jentry_array
					// C: Entry in root file for the end begining of Spill_number == 1 -> jentry_array + nentries_1
					// This code can not know the entry for the end of the spill, but we can
					// get it by knowing the total numbers of entries.
					// D: Entry in root file for the time begining of Spill_number == X -> jentry_array_X

					int jentry_array,jentry_array2,jentry_array3,jentry_array4,jentry_array5,jentry_array6;
					Double_t Time_begin_spill_1,Time_begin_spill_2,Time_begin_spill_3,Time_begin_spill_4,Time_begin_spill_5,Time_begin_spill_6;
					Double_t t_o_spill_1, t_o_spill_2, t_o_spill_3, t_o_spill_4, t_o_spill_5, t_o_spill_6;
					Double_t exists_spill_1, exists_spill_2, exists_spill_3, exists_spill_4, exists_spill_5, exists_spill_6;

					exists_spill_1 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 1");
					//myfile3 << "Existe el spill 1?: " << exists_spill_1 << endl;
					exists_spill_2 = fChain->GetEntries("Time && In_spill>0.5  && Spill_number == 2");
					//myfile3 << "Existe el spill 2?: " <<exists_spill_2 << endl;
					exists_spill_3 = fChain->GetEntries("Time && In_spill>0.5  && Spill_number == 3");
					//myfile3 << "Existe el spill 3?: " <<exists_spill_3 << endl;
					exists_spill_4 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 4");
					//myfile3 << "Existe el spill 4?: " <<exists_spill_4 << endl;
					exists_spill_5 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 5");
					//myfile3 << "Existe el spill 5?: " <<exists_spill_5 << endl;
					exists_spill_6 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 6");
					//myfile3 << "Existe el spill 6?: " <<exists_spill_6 << endl;

					// ================= LOOP 0 : Begin of the Variable Time and =================== //

					if (fChain == 0) return; Long64_t nentries = fChain->GetEntries(); Long64_t nbytes = 0, nb = 0;
					Double_t signal1_t_begin_spill_1, signal1_t_begin_spill_2, signal1_t_begin_spill_3, signal1_t_begin_spill_4, signal1_t_begin_spill_5, signal1_t_begin_spill_6;

					signal1_t_begin_spill_1 = 0; 			signal1_t_begin_spill_2 = 0;
					signal1_t_begin_spill_3 = 0;			signal1_t_begin_spill_4 = 0;
					signal1_t_begin_spill_5 = 0;			signal1_t_begin_spill_6 = 0;

					for (Long64_t jentry=0; jentry<1;jentry++) {
							Long64_t ientry = LoadTree(jentry); if (ientry < 0) break;
							nb = fChain->GetEntry(jentry);   nbytes += nb; t_begin[i] = (Double_t) Time;
							//myfile2 << "t_begin: "<< t_begin[i] << endl;
					 }

						// ================= LOOP 1 : Begin Time for the Spill_number == 1 =================== //

					// ================= LOOP 1 : Begin Time for the Spill_number == 1 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
						 Long64_t ientry = LoadTree(jentry);                //if (ientry < 0) break;
						 nb = fChain->GetEntry(jentry);   nbytes += nb;

						 if (In_spill > 0.5 ){if (Spill_number == 1 && exists_spill_1 != 0 ){
							 //jentry_array= (Double_t) jentry;

							Time_begin_spill_1 = (Double_t) Time - t_begin[i];
							t_o_spill_1 = (Double_t) Time;
							signal1_t_begin_spill_1 = 1;
																				break ;                  }                 }             }

					// ================= LOOP 2 : Begin Time for the Spill_number == 2 =================== //

					 for (Long64_t jentry=0; jentry<nentries;jentry++) {
						 Long64_t ientry = LoadTree(jentry);                 //if (ientry < 0) break;
							nb = fChain->GetEntry(jentry);   nbytes += nb;

							if (In_spill > 0.5 ){ if (Spill_number == 2 ){ jentry_array2= (Double_t) jentry;
								Time_begin_spill_2 = (Double_t) Time - t_begin[i];
								t_o_spill_2 = (Double_t) Time;
								////myfile << "jentry_array2: "<< jentry_array2 << endl;
								 //myfile2 << "Time_spill_2 "<< Time_begin_spill_2 << endl;
								 signal1_t_begin_spill_2 = 1;
										break ;                    }                  }              }

					// ================= LOOP 3 : Begin Time for the Spill_number == 3 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
							 Long64_t ientry = LoadTree(jentry);                 //if (ientry < 0) break;
							 nb = fChain->GetEntry(jentry);   nbytes += nb;

							 if (In_spill > 0.5 ){if (Spill_number == 3 ){jentry_array3= (Double_t) jentry;
								Time_begin_spill_3 = (Double_t) Time - t_begin[i];
								t_o_spill_3 = (Double_t) Time;
								 ////myfile << "jentry_array3: "<< jentry_array3 << endl;
								 //myfile2 << "Time_spill_3 "<< Time_begin_spill_3 << endl;
								 signal1_t_begin_spill_3 = 1;
										 break ;                     }                   }               }

					// ================= LOOP 4 : Begin Time for the Spill_number == 4 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
								Long64_t ientry = LoadTree(jentry);
								// if (ientry < 0) break;
								nb = fChain->GetEntry(jentry);   nbytes += nb;

								if (In_spill > 0.5 ){if (Spill_number == 4 ){jentry_array4= (Double_t) jentry;
								Time_begin_spill_4 = (Double_t) Time - t_begin[i];
								t_o_spill_4 = (Double_t) Time;
								 ////myfile << "jentry_array4: "<< jentry_array4 << endl;
								 //myfile2 << "Time_spill_4 "<< Time_begin_spill_4 << endl;
								 signal1_t_begin_spill_4 = 1;
											break ;                      }                    }                }

					// ================= LOOP 5 : Begin Time for the Spill_number == 5 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
								 Long64_t ientry = LoadTree(jentry);
								 //if (ientry < 0) break;
								 nb = fChain->GetEntry(jentry);   nbytes += nb;

								 if (In_spill > 0.5 ){if (Spill_number == 5 ){jentry_array5= (Double_t) jentry;
								Time_begin_spill_5 = (Double_t) Time - t_begin[i];
								t_o_spill_5 = (Double_t) Time;
								 ////myfile << "jentry_array5: "<< jentry_array5 << endl;
								 //myfile2 << "Time_spill_5 "<< Time_begin_spill_5 << endl;
								 signal1_t_begin_spill_5 = 1;
											 break ;                       }                     }                 }

					// ================= LOOP 6 : Begin Time for the Spill_number == 2 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
									Long64_t ientry = LoadTree(jentry);
									//if (ientry < 0) break;
									nb = fChain->GetEntry(jentry);   nbytes += nb;

									if (In_spill > 0.5 ){if (Spill_number == 6 ){jentry_array6= (Double_t) jentry;
								Time_begin_spill_6 = (Double_t) Time - t_begin[i];
								t_o_spill_6 = (Double_t) Time;
								 ////myfile << "jentry_array6: "<< jentry_array6 << endl;
								 //myfile2 << "Time_spill_6 "<< Time_begin_spill_6 << endl;
								 signal1_t_begin_spill_6 = 1;
												break ;                        }                      }                  }

					Float_t interval_between_spills = 0.0;

					if (fChain == 0) return;
					 Long64_t nentries = fChain->GetEntries();
					 Long64_t nbytes = 0, nb = 0;

					 Double_t duration_spill_1, duration_spill_2, duration_spill_3, duration_spill_4, duration_spill_5, duration_spill_6;

					 for (Long64_t jentry=0; jentry<nentries;jentry++) {
						 Long64_t ientry = LoadTree(jentry);
						 //if (ientry < 0) break;
						 nb = fChain->GetEntry(jentry);   nbytes += nb;

							//Conditions for Spill has actual values

							Time_spill_1b = -1; Time_spill_2b = -1; Time_spill_3b = -1;
							Time_spill_4b = -1; Time_spill_5b = -1; Time_spill_6b = -1;
							mi_cycle = 0;

		      	if (In_spill > 0.5 )              {
		          if (Spill_number == 1  )                 {

		                  Time_spill_1 = (Double_t) Time -t_begin[i];
		                  duration_spill_1 = Time_spill_1 - Time_begin_spill_1;

		                  Time_spill_1b = (Double_t) Time - t_o_spill_1;
		                  Spill_numberb = 1;
		                  tree_spill->Fill();


		            }
		            else if (Spill_number == 2 )
		            {
		                  Time_spill_2= (Double_t) Time -t_begin[i];
		                  duration_spill_2 = Time_spill_2 - Time_begin_spill_2;


		                  Time_spill_2b = (Double_t) Time - t_o_spill_2;
		                  Spill_numberb = 2;
		                  tree_spill->Fill();

		            }

		            else if (Spill_number == 3  )
		            {
		                  Time_spill_3= (Double_t) Time -t_begin[i];
		                  duration_spill_3 = Time_spill_3 - Time_begin_spill_3;

		                  Time_spill_3b = (Double_t) Time - t_o_spill_3;
		                  Spill_numberb = 3;
		                  tree_spill->Fill();

		             }

		           else if (Spill_number == 4  )
		           {
		                 Time_spill_4= (Double_t) Time -t_begin[i];
		                 duration_spill_4 = Time_spill_4 - Time_begin_spill_4;


		                 Time_spill_4b = (Double_t) Time - t_o_spill_4 ;
		                 Spill_numberb = 4;
		                 tree_spill->Fill();
		          	}

		          	else if (Spill_number == 5  )
		          	{
		                Time_spill_5= (Double_t) Time -t_begin[i];
		                duration_spill_5 = Time_spill_5 - Time_begin_spill_5;


		                Time_spill_5b = (Double_t) Time - t_o_spill_5 ;
		                Spill_numberb = 5;
		                tree_spill->Fill();
		          	}

		         	 else if (Spill_number == 6  )
		         	 {
		               Time_spill_6= (Double_t) Time -t_begin[i];
		               duration_spill_6 = Time_spill_6 - Time_begin_spill_6;


		               Time_spill_6b = (Double_t) Time - t_o_spill_6;
		               Spill_numberb = 6;
		               tree_spill->Fill();
		         	 }

		        } // end of:  if (In_spill > 0.5 )
		 			}//end of: for (Long64_t jentry=0; jentry<nentries;jentry++)

					  	// ## 1

						  duration_spill =  duration_spill_1;
						  category = 1;
						  mi_cycle = 0;
							//myfile << mi_cycle << endl;
							//myfile4 << duration_spill << endl;
						  spill_global->Fill();

							// ## 2

							if(signal1_t_begin_spill_1 == 1 && signal1_t_begin_spill_2 == 1){

								  duration_spill =  duration_spill_2;
								  mi_cycle = t_o_spill_2 - t_o_spill_1;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

								  duration_spill =  duration_spill_2;
								  mi_cycle = 0;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							// ## 3

							if(signal1_t_begin_spill_3 == 1 && signal1_t_begin_spill_2 == 1){

								  duration_spill =  duration_spill_3;
								  mi_cycle = t_o_spill_3 - t_o_spill_2;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

								  duration_spill =  duration_spill_3;
								  mi_cycle = 0;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}

						  // ## 4
							if(signal1_t_begin_spill_3 == 1 && signal1_t_begin_spill_4 == 1){

								  duration_spill =  duration_spill_4;
								  mi_cycle =  t_o_spill_4 - t_o_spill_3;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

									duration_spill =  duration_spill_4;
								  mi_cycle = 0;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
						  // ## 5

							if(signal1_t_begin_spill_4 == 1 && signal1_t_begin_spill_5 == 1){

								  duration_spill =  duration_spill_5;
								  mi_cycle = t_o_spill_5 - t_o_spill_4;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

							  duration_spill =  duration_spill_5;
							  mi_cycle = 0 ;
							  category = 1;
							  //myfile << mi_cycle << endl;
								//myfile4 << duration_spill << endl;
							  spill_global->Fill();

							}
						  // ## 6

							if(signal1_t_begin_spill_6 == 1 && signal1_t_begin_spill_5 == 1){

							  duration_spill =  duration_spill_6;
							  mi_cycle = t_o_spill_6 - t_o_spill_5;
							  category = 1;
							  //myfile << mi_cycle << endl;
								//myfile4 << duration_spill << endl;
							  spill_global->Fill();

							}
							else {

							  duration_spill =  duration_spill_6;
							  mi_cycle = 0;
							  category = 1;
							  //myfile << mi_cycle << endl;
								//myfile4 << duration_spill << endl;
							  spill_global->Fill();

							}


		}  // End For the ROOT files 8GeV Neg

		// == 6 GeV Neg

		  for(Int_t i=74+71+74+68; i<74+71+74+68+69; i++){ //For() over all the root files
			polarityb = -1;
			energyb = 6;
			cout <<  i ;

				t_begin[i]=0;
				f[i] = (TFile*)gROOT->GetListOfFiles()->FindObject(name_file[i]);

				if (!f[i] || !f[i]->IsOpen()) {
					 f[i] = new TFile(name_file[i],"READ");
				}

				f[i]->GetObject("CAMACTree",tree[i]);
		   	Init(tree[i]);      //fChain equal to the tree corresponding to the array_file_root[i]
		    cout <<  i  << "..." << endl  ;

				//  =============================== LOOP ================================= //
				//  Input: root file of TB with the most importat variable: Spill_number
				//  Loop 0 will record the begining of the time in the root file in order to remove the unix time and use only seconds
				//  Loop 1-6 will get the begining in time for each spill for future uses
				//  Loop 7 : creates the results root file with the spills but now calibrated to the begining of the spill

				// IMPORTANT Values: int jentry_array,jentry_array2,jentry_array3,jentry_array4,jentry_array5,jentry_array6;
					//
					// | ------- | ----- Spill_number == 1 ----- | ----- Spill_number == 2 ----- | ---
					//
					//
					//  A ------- B ---------------------------- C ----------------------------- D ----
					// Variables:
					// A: Time begining of the root file -> t_begin
					// B: Entry in root file for the time begining of Spill_number == 1 -> jentry_array
					// C: Entry in root file for the end begining of Spill_number == 1 -> jentry_array + nentries_1
					// This code can not know the entry for the end of the spill, but we can
					// get it by knowing the total numbers of entries.
					// D: Entry in root file for the time begining of Spill_number == X -> jentry_array_X

					int jentry_array,jentry_array2,jentry_array3,jentry_array4,jentry_array5,jentry_array6;
					Double_t Time_begin_spill_1,Time_begin_spill_2,Time_begin_spill_3,Time_begin_spill_4,Time_begin_spill_5,Time_begin_spill_6;
					Double_t t_o_spill_1, t_o_spill_2, t_o_spill_3, t_o_spill_4, t_o_spill_5, t_o_spill_6;
					Double_t exists_spill_1, exists_spill_2, exists_spill_3, exists_spill_4, exists_spill_5, exists_spill_6;

					exists_spill_1 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 1");
					//myfile3 << "Existe el spill 1?: " << exists_spill_1 << endl;
					exists_spill_2 = fChain->GetEntries("Time && In_spill>0.5  && Spill_number == 2");
					//myfile3 << "Existe el spill 2?: " <<exists_spill_2 << endl;
					exists_spill_3 = fChain->GetEntries("Time && In_spill>0.5  && Spill_number == 3");
					//myfile3 << "Existe el spill 3?: " <<exists_spill_3 << endl;
					exists_spill_4 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 4");
					//myfile3 << "Existe el spill 4?: " <<exists_spill_4 << endl;
					exists_spill_5 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 5");
					//myfile3 << "Existe el spill 5?: " <<exists_spill_5 << endl;
					exists_spill_6 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 6");
					//myfile3 << "Existe el spill 6?: " <<exists_spill_6 << endl;

					// ================= LOOP 0 : Begin of the Variable Time and =================== //

					if (fChain == 0) return; Long64_t nentries = fChain->GetEntries(); Long64_t nbytes = 0, nb = 0;
					Double_t signal1_t_begin_spill_1, signal1_t_begin_spill_2, signal1_t_begin_spill_3, signal1_t_begin_spill_4, signal1_t_begin_spill_5, signal1_t_begin_spill_6;

					signal1_t_begin_spill_1 = 0; 			signal1_t_begin_spill_2 = 0;
					signal1_t_begin_spill_3 = 0;			signal1_t_begin_spill_4 = 0;
					signal1_t_begin_spill_5 = 0;			signal1_t_begin_spill_6 = 0;

					for (Long64_t jentry=0; jentry<1;jentry++) {
							Long64_t ientry = LoadTree(jentry); if (ientry < 0) break;
							nb = fChain->GetEntry(jentry);   nbytes += nb; t_begin[i] = (Double_t) Time;
							//myfile2 << "t_begin: "<< t_begin[i] << endl;
					 }

						// ================= LOOP 1 : Begin Time for the Spill_number == 1 =================== //

					// ================= LOOP 1 : Begin Time for the Spill_number == 1 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
						 Long64_t ientry = LoadTree(jentry);                //if (ientry < 0) break;
						 nb = fChain->GetEntry(jentry);   nbytes += nb;

						 if (In_spill > 0.5 ){if (Spill_number == 1 && exists_spill_1 != 0 ){
							 //jentry_array= (Double_t) jentry;

							Time_begin_spill_1 = (Double_t) Time - t_begin[i];
							t_o_spill_1 = (Double_t) Time;
							signal1_t_begin_spill_1 = 1;
																				break ;                  }                 }             }

					// ================= LOOP 2 : Begin Time for the Spill_number == 2 =================== //

					 for (Long64_t jentry=0; jentry<nentries;jentry++) {
						 Long64_t ientry = LoadTree(jentry);                 //if (ientry < 0) break;
							nb = fChain->GetEntry(jentry);   nbytes += nb;

							if (In_spill > 0.5 ){ if (Spill_number == 2 ){ jentry_array2= (Double_t) jentry;
								Time_begin_spill_2 = (Double_t) Time - t_begin[i];
								t_o_spill_2 = (Double_t) Time;
								////myfile << "jentry_array2: "<< jentry_array2 << endl;
								 //myfile2 << "Time_spill_2 "<< Time_begin_spill_2 << endl;
								 signal1_t_begin_spill_2 = 1;
										break ;                    }                  }              }

					// ================= LOOP 3 : Begin Time for the Spill_number == 3 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
							 Long64_t ientry = LoadTree(jentry);                 //if (ientry < 0) break;
							 nb = fChain->GetEntry(jentry);   nbytes += nb;

							 if (In_spill > 0.5 ){if (Spill_number == 3 ){jentry_array3= (Double_t) jentry;
								Time_begin_spill_3 = (Double_t) Time - t_begin[i];
								t_o_spill_3 = (Double_t) Time;
								 ////myfile << "jentry_array3: "<< jentry_array3 << endl;
								 //myfile2 << "Time_spill_3 "<< Time_begin_spill_3 << endl;
								 signal1_t_begin_spill_3 = 1;
										 break ;                     }                   }               }

					// ================= LOOP 4 : Begin Time for the Spill_number == 4 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
								Long64_t ientry = LoadTree(jentry);
								// if (ientry < 0) break;
								nb = fChain->GetEntry(jentry);   nbytes += nb;

								if (In_spill > 0.5 ){if (Spill_number == 4 ){jentry_array4= (Double_t) jentry;
								Time_begin_spill_4 = (Double_t) Time - t_begin[i];
								t_o_spill_4 = (Double_t) Time;
								 ////myfile << "jentry_array4: "<< jentry_array4 << endl;
								 //myfile2 << "Time_spill_4 "<< Time_begin_spill_4 << endl;
								 signal1_t_begin_spill_4 = 1;
											break ;                      }                    }                }

					// ================= LOOP 5 : Begin Time for the Spill_number == 5 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
								 Long64_t ientry = LoadTree(jentry);
								 //if (ientry < 0) break;
								 nb = fChain->GetEntry(jentry);   nbytes += nb;

								 if (In_spill > 0.5 ){if (Spill_number == 5 ){jentry_array5= (Double_t) jentry;
								Time_begin_spill_5 = (Double_t) Time - t_begin[i];
								t_o_spill_5 = (Double_t) Time;
								 ////myfile << "jentry_array5: "<< jentry_array5 << endl;
								 //myfile2 << "Time_spill_5 "<< Time_begin_spill_5 << endl;
								 signal1_t_begin_spill_5 = 1;
											 break ;                       }                     }                 }

					// ================= LOOP 6 : Begin Time for the Spill_number == 2 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
									Long64_t ientry = LoadTree(jentry);
									//if (ientry < 0) break;
									nb = fChain->GetEntry(jentry);   nbytes += nb;

									if (In_spill > 0.5 ){if (Spill_number == 6 ){jentry_array6= (Double_t) jentry;
								Time_begin_spill_6 = (Double_t) Time - t_begin[i];
								t_o_spill_6 = (Double_t) Time;
								 ////myfile << "jentry_array6: "<< jentry_array6 << endl;
								 //myfile2 << "Time_spill_6 "<< Time_begin_spill_6 << endl;
								 signal1_t_begin_spill_6 = 1;
												break ;                        }                      }                  }

					Float_t interval_between_spills = 0.0;

					if (fChain == 0) return;
					 Long64_t nentries = fChain->GetEntries();
					 Long64_t nbytes = 0, nb = 0;

					 Double_t duration_spill_1, duration_spill_2, duration_spill_3, duration_spill_4, duration_spill_5, duration_spill_6;

					 for (Long64_t jentry=0; jentry<nentries;jentry++) {
						 Long64_t ientry = LoadTree(jentry);
						 //if (ientry < 0) break;
						 nb = fChain->GetEntry(jentry);   nbytes += nb;

							//Conditions for Spill has actual values

							Time_spill_1b = -1; Time_spill_2b = -1; Time_spill_3b = -1;
							Time_spill_4b = -1; Time_spill_5b = -1; Time_spill_6b = -1;
							mi_cycle = 0;

		      	if (In_spill > 0.5 )              {
		          if (Spill_number == 1  )                 {

		                  Time_spill_1 = (Double_t) Time -t_begin[i];
		                  duration_spill_1 = Time_spill_1 - Time_begin_spill_1;

		                  Time_spill_1b = (Double_t) Time - t_o_spill_1;
		                  Spill_numberb = 1;
		                  tree_spill->Fill();


		            }
		            else if (Spill_number == 2 )
		            {
		                  Time_spill_2= (Double_t) Time -t_begin[i];
		                  duration_spill_2 = Time_spill_2 - Time_begin_spill_2;


		                  Time_spill_2b = (Double_t) Time - t_o_spill_2;
		                  Spill_numberb = 2;
		                  tree_spill->Fill();

		            }

		            else if (Spill_number == 3  )
		            {
		                  Time_spill_3= (Double_t) Time -t_begin[i];
		                  duration_spill_3 = Time_spill_3 - Time_begin_spill_3;

		                  Time_spill_3b = (Double_t) Time - t_o_spill_3;
		                  Spill_numberb = 3;
		                  tree_spill->Fill();

		             }

		           else if (Spill_number == 4  )
		           {
		                 Time_spill_4= (Double_t) Time -t_begin[i];
		                 duration_spill_4 = Time_spill_4 - Time_begin_spill_4;


		                 Time_spill_4b = (Double_t) Time - t_o_spill_4 ;
		                 Spill_numberb = 4;
		                 tree_spill->Fill();
		          	}

		          	else if (Spill_number == 5  )
		          	{
		                Time_spill_5= (Double_t) Time -t_begin[i];
		                duration_spill_5 = Time_spill_5 - Time_begin_spill_5;


		                Time_spill_5b = (Double_t) Time - t_o_spill_5 ;
		                Spill_numberb = 5;
		                tree_spill->Fill();
		          	}

		         	 else if (Spill_number == 6  )
		         	 {
		               Time_spill_6= (Double_t) Time -t_begin[i];
		               duration_spill_6 = Time_spill_6 - Time_begin_spill_6;


		               Time_spill_6b = (Double_t) Time - t_o_spill_6;
		               Spill_numberb = 6;
		               tree_spill->Fill();
		         	 }

		        } // end of:  if (In_spill > 0.5 )
		 			}//end of: for (Long64_t jentry=0; jentry<nentries;jentry++)

					  	// ## 1

						  duration_spill =  duration_spill_1;
						  category = 1;
						  mi_cycle = 0;
							//myfile << mi_cycle << endl;
							//myfile4 << duration_spill << endl;
						  spill_global->Fill();

							// ## 2

							if(signal1_t_begin_spill_1 == 1 && signal1_t_begin_spill_2 == 1){

								  duration_spill =  duration_spill_2;
								  mi_cycle = t_o_spill_2 - t_o_spill_1;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

								  duration_spill =  duration_spill_2;
								  mi_cycle = 0;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							// ## 3

							if(signal1_t_begin_spill_3 == 1 && signal1_t_begin_spill_2 == 1){

								  duration_spill =  duration_spill_3;
								  mi_cycle = t_o_spill_3 - t_o_spill_2;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

								  duration_spill =  duration_spill_3;
								  mi_cycle = 0;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}

						  // ## 4
							if(signal1_t_begin_spill_3 == 1 && signal1_t_begin_spill_4 == 1){

								  duration_spill =  duration_spill_4;
								  mi_cycle =  t_o_spill_4 - t_o_spill_3;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

									duration_spill =  duration_spill_4;
								  mi_cycle = 0;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
						  // ## 5

							if(signal1_t_begin_spill_4 == 1 && signal1_t_begin_spill_5 == 1){

								  duration_spill =  duration_spill_5;
								  mi_cycle = t_o_spill_5 - t_o_spill_4;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

							  duration_spill =  duration_spill_5;
							  mi_cycle = 0 ;
							  category = 1;
							  //myfile << mi_cycle << endl;
								//myfile4 << duration_spill << endl;
							  spill_global->Fill();

							}
						  // ## 6

							if(signal1_t_begin_spill_6 == 1 && signal1_t_begin_spill_5 == 1){

							  duration_spill =  duration_spill_6;
							  mi_cycle = t_o_spill_6 - t_o_spill_5;
							  category = 1;
							  //myfile << mi_cycle << endl;
								//myfile4 << duration_spill << endl;
							  spill_global->Fill();

							}
							else {

							  duration_spill =  duration_spill_6;
							  mi_cycle = 0;
							  category = 1;
							  //myfile << mi_cycle << endl;
								//myfile4 << duration_spill << endl;
							  spill_global->Fill();

							}


		}  // End For the ROOT files 6GeV Neg


		// == 4 GeV Neg

		  for(Int_t i=74+71+74+68+69; i<74+71+74+68+69+74; i++){ //For() over all the root files
			polarityb = -1;
			energyb = 4;
			cout <<  i ;

				t_begin[i]=0;
				f[i] = (TFile*)gROOT->GetListOfFiles()->FindObject(name_file[i]);

				if (!f[i] || !f[i]->IsOpen()) {
					 f[i] = new TFile(name_file[i],"READ");
				}

				f[i]->GetObject("CAMACTree",tree[i]);
		   	Init(tree[i]);      //fChain equal to the tree corresponding to the array_file_root[i]
		    cout <<  i  << "..." << endl  ;

				//  =============================== LOOP ================================= //
				//  Input: root file of TB with the most importat variable: Spill_number
				//  Loop 0 will record the begining of the time in the root file in order to remove the unix time and use only seconds
				//  Loop 1-6 will get the begining in time for each spill for future uses
				//  Loop 7 : creates the results root file with the spills but now calibrated to the begining of the spill

				// IMPORTANT Values: int jentry_array,jentry_array2,jentry_array3,jentry_array4,jentry_array5,jentry_array6;
					//
					// | ------- | ----- Spill_number == 1 ----- | ----- Spill_number == 2 ----- | ---
					//
					//
					//  A ------- B ---------------------------- C ----------------------------- D ----
					// Variables:
					// A: Time begining of the root file -> t_begin
					// B: Entry in root file for the time begining of Spill_number == 1 -> jentry_array
					// C: Entry in root file for the end begining of Spill_number == 1 -> jentry_array + nentries_1
					// This code can not know the entry for the end of the spill, but we can
					// get it by knowing the total numbers of entries.
					// D: Entry in root file for the time begining of Spill_number == X -> jentry_array_X

					int jentry_array,jentry_array2,jentry_array3,jentry_array4,jentry_array5,jentry_array6;
					Double_t Time_begin_spill_1,Time_begin_spill_2,Time_begin_spill_3,Time_begin_spill_4,Time_begin_spill_5,Time_begin_spill_6;
					Double_t t_o_spill_1, t_o_spill_2, t_o_spill_3, t_o_spill_4, t_o_spill_5, t_o_spill_6;
					Double_t exists_spill_1, exists_spill_2, exists_spill_3, exists_spill_4, exists_spill_5, exists_spill_6;

					exists_spill_1 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 1");
					//myfile3 << "Existe el spill 1?: " << exists_spill_1 << endl;
					exists_spill_2 = fChain->GetEntries("Time && In_spill>0.5  && Spill_number == 2");
					//myfile3 << "Existe el spill 2?: " <<exists_spill_2 << endl;
					exists_spill_3 = fChain->GetEntries("Time && In_spill>0.5  && Spill_number == 3");
					//myfile3 << "Existe el spill 3?: " <<exists_spill_3 << endl;
					exists_spill_4 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 4");
					//myfile3 << "Existe el spill 4?: " <<exists_spill_4 << endl;
					exists_spill_5 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 5");
					//myfile3 << "Existe el spill 5?: " <<exists_spill_5 << endl;
					exists_spill_6 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 6");
					//myfile3 << "Existe el spill 6?: " <<exists_spill_6 << endl;

					// ================= LOOP 0 : Begin of the Variable Time and =================== //

					if (fChain == 0) return; Long64_t nentries = fChain->GetEntries(); Long64_t nbytes = 0, nb = 0;
					Double_t signal1_t_begin_spill_1, signal1_t_begin_spill_2, signal1_t_begin_spill_3, signal1_t_begin_spill_4, signal1_t_begin_spill_5, signal1_t_begin_spill_6;

					signal1_t_begin_spill_1 = 0; 			signal1_t_begin_spill_2 = 0;
					signal1_t_begin_spill_3 = 0;			signal1_t_begin_spill_4 = 0;
					signal1_t_begin_spill_5 = 0;			signal1_t_begin_spill_6 = 0;

					for (Long64_t jentry=0; jentry<1;jentry++) {
							Long64_t ientry = LoadTree(jentry); if (ientry < 0) break;
							nb = fChain->GetEntry(jentry);   nbytes += nb; t_begin[i] = (Double_t) Time;
							//myfile2 << "t_begin: "<< t_begin[i] << endl;
					 }

						// ================= LOOP 1 : Begin Time for the Spill_number == 1 =================== //

					// ================= LOOP 1 : Begin Time for the Spill_number == 1 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
						 Long64_t ientry = LoadTree(jentry);                //if (ientry < 0) break;
						 nb = fChain->GetEntry(jentry);   nbytes += nb;

						 if (In_spill > 0.5 ){if (Spill_number == 1 && exists_spill_1 != 0 ){
							 //jentry_array= (Double_t) jentry;

							Time_begin_spill_1 = (Double_t) Time - t_begin[i];
							t_o_spill_1 = (Double_t) Time;
							signal1_t_begin_spill_1 = 1;
																				break ;                  }                 }             }

					// ================= LOOP 2 : Begin Time for the Spill_number == 2 =================== //

					 for (Long64_t jentry=0; jentry<nentries;jentry++) {
						 Long64_t ientry = LoadTree(jentry);                 //if (ientry < 0) break;
							nb = fChain->GetEntry(jentry);   nbytes += nb;

							if (In_spill > 0.5 ){ if (Spill_number == 2 ){ jentry_array2= (Double_t) jentry;
								Time_begin_spill_2 = (Double_t) Time - t_begin[i];
								t_o_spill_2 = (Double_t) Time;
								////myfile << "jentry_array2: "<< jentry_array2 << endl;
								 //myfile2 << "Time_spill_2 "<< Time_begin_spill_2 << endl;
								 signal1_t_begin_spill_2 = 1;
										break ;                    }                  }              }

					// ================= LOOP 3 : Begin Time for the Spill_number == 3 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
							 Long64_t ientry = LoadTree(jentry);                 //if (ientry < 0) break;
							 nb = fChain->GetEntry(jentry);   nbytes += nb;

							 if (In_spill > 0.5 ){if (Spill_number == 3 ){jentry_array3= (Double_t) jentry;
								Time_begin_spill_3 = (Double_t) Time - t_begin[i];
								t_o_spill_3 = (Double_t) Time;
								 ////myfile << "jentry_array3: "<< jentry_array3 << endl;
								 //myfile2 << "Time_spill_3 "<< Time_begin_spill_3 << endl;
								 signal1_t_begin_spill_3 = 1;
										 break ;                     }                   }               }

					// ================= LOOP 4 : Begin Time for the Spill_number == 4 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
								Long64_t ientry = LoadTree(jentry);
								// if (ientry < 0) break;
								nb = fChain->GetEntry(jentry);   nbytes += nb;

								if (In_spill > 0.5 ){if (Spill_number == 4 ){jentry_array4= (Double_t) jentry;
								Time_begin_spill_4 = (Double_t) Time - t_begin[i];
								t_o_spill_4 = (Double_t) Time;
								 ////myfile << "jentry_array4: "<< jentry_array4 << endl;
								 //myfile2 << "Time_spill_4 "<< Time_begin_spill_4 << endl;
								 signal1_t_begin_spill_4 = 1;
											break ;                      }                    }                }

					// ================= LOOP 5 : Begin Time for the Spill_number == 5 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
								 Long64_t ientry = LoadTree(jentry);
								 //if (ientry < 0) break;
								 nb = fChain->GetEntry(jentry);   nbytes += nb;

								 if (In_spill > 0.5 ){if (Spill_number == 5 ){jentry_array5= (Double_t) jentry;
								Time_begin_spill_5 = (Double_t) Time - t_begin[i];
								t_o_spill_5 = (Double_t) Time;
								 ////myfile << "jentry_array5: "<< jentry_array5 << endl;
								 //myfile2 << "Time_spill_5 "<< Time_begin_spill_5 << endl;
								 signal1_t_begin_spill_5 = 1;
											 break ;                       }                     }                 }

					// ================= LOOP 6 : Begin Time for the Spill_number == 2 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
									Long64_t ientry = LoadTree(jentry);
									//if (ientry < 0) break;
									nb = fChain->GetEntry(jentry);   nbytes += nb;

									if (In_spill > 0.5 ){if (Spill_number == 6 ){jentry_array6= (Double_t) jentry;
								Time_begin_spill_6 = (Double_t) Time - t_begin[i];
								t_o_spill_6 = (Double_t) Time;
								 ////myfile << "jentry_array6: "<< jentry_array6 << endl;
								 //myfile2 << "Time_spill_6 "<< Time_begin_spill_6 << endl;
								 signal1_t_begin_spill_6 = 1;
												break ;                        }                      }                  }

					Float_t interval_between_spills = 0.0;

					if (fChain == 0) return;
					 Long64_t nentries = fChain->GetEntries();
					 Long64_t nbytes = 0, nb = 0;

					 Double_t duration_spill_1, duration_spill_2, duration_spill_3, duration_spill_4, duration_spill_5, duration_spill_6;

					 for (Long64_t jentry=0; jentry<nentries;jentry++) {
						 Long64_t ientry = LoadTree(jentry);
						 //if (ientry < 0) break;
						 nb = fChain->GetEntry(jentry);   nbytes += nb;

							//Conditions for Spill has actual values

							Time_spill_1b = -1; Time_spill_2b = -1; Time_spill_3b = -1;
							Time_spill_4b = -1; Time_spill_5b = -1; Time_spill_6b = -1;
							mi_cycle = 0;

		      	if (In_spill > 0.5 )              {
		          if (Spill_number == 1  )                 {

		                  Time_spill_1 = (Double_t) Time -t_begin[i];
		                  duration_spill_1 = Time_spill_1 - Time_begin_spill_1;

		                  Time_spill_1b = (Double_t) Time - t_o_spill_1;
		                  Spill_numberb = 1;
		                  tree_spill->Fill();


		            }
		            else if (Spill_number == 2 )
		            {
		                  Time_spill_2= (Double_t) Time -t_begin[i];
		                  duration_spill_2 = Time_spill_2 - Time_begin_spill_2;


		                  Time_spill_2b = (Double_t) Time - t_o_spill_2;
		                  Spill_numberb = 2;
		                  tree_spill->Fill();

		            }

		            else if (Spill_number == 3  )
		            {
		                  Time_spill_3= (Double_t) Time -t_begin[i];
		                  duration_spill_3 = Time_spill_3 - Time_begin_spill_3;

		                  Time_spill_3b = (Double_t) Time - t_o_spill_3;
		                  Spill_numberb = 3;
		                  tree_spill->Fill();

		             }

		           else if (Spill_number == 4  )
		           {
		                 Time_spill_4= (Double_t) Time -t_begin[i];
		                 duration_spill_4 = Time_spill_4 - Time_begin_spill_4;


		                 Time_spill_4b = (Double_t) Time - t_o_spill_4 ;
		                 Spill_numberb = 4;
		                 tree_spill->Fill();
		          	}

		          	else if (Spill_number == 5  )
		          	{
		                Time_spill_5= (Double_t) Time -t_begin[i];
		                duration_spill_5 = Time_spill_5 - Time_begin_spill_5;


		                Time_spill_5b = (Double_t) Time - t_o_spill_5 ;
		                Spill_numberb = 5;
		                tree_spill->Fill();
		          	}

		         	 else if (Spill_number == 6  )
		         	 {
		               Time_spill_6= (Double_t) Time -t_begin[i];
		               duration_spill_6 = Time_spill_6 - Time_begin_spill_6;


		               Time_spill_6b = (Double_t) Time - t_o_spill_6;
		               Spill_numberb = 6;
		               tree_spill->Fill();
		         	 }

		        } // end of:  if (In_spill > 0.5 )
		 			}//end of: for (Long64_t jentry=0; jentry<nentries;jentry++)

					  	// ## 1

						  duration_spill =  duration_spill_1;
						  category = 1;
						  mi_cycle = 0;
							//myfile << mi_cycle << endl;
							//myfile4 << duration_spill << endl;
						  spill_global->Fill();

							// ## 2

							if(signal1_t_begin_spill_1 == 1 && signal1_t_begin_spill_2 == 1){

								  duration_spill =  duration_spill_2;
								  mi_cycle = t_o_spill_2 - t_o_spill_1;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

								  duration_spill =  duration_spill_2;
								  mi_cycle = 0;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							// ## 3

							if(signal1_t_begin_spill_3 == 1 && signal1_t_begin_spill_2 == 1){

								  duration_spill =  duration_spill_3;
								  mi_cycle = t_o_spill_3 - t_o_spill_2;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

								  duration_spill =  duration_spill_3;
								  mi_cycle = 0;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}

						  // ## 4
							if(signal1_t_begin_spill_3 == 1 && signal1_t_begin_spill_4 == 1){

								  duration_spill =  duration_spill_4;
								  mi_cycle =  t_o_spill_4 - t_o_spill_3;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

									duration_spill =  duration_spill_4;
								  mi_cycle = 0;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
						  // ## 5

							if(signal1_t_begin_spill_4 == 1 && signal1_t_begin_spill_5 == 1){

								  duration_spill =  duration_spill_5;
								  mi_cycle = t_o_spill_5 - t_o_spill_4;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

							  duration_spill =  duration_spill_5;
							  mi_cycle = 0 ;
							  category = 1;
							  //myfile << mi_cycle << endl;
								//myfile4 << duration_spill << endl;
							  spill_global->Fill();

							}
						  // ## 6

							if(signal1_t_begin_spill_6 == 1 && signal1_t_begin_spill_5 == 1){

							  duration_spill =  duration_spill_6;
							  mi_cycle = t_o_spill_6 - t_o_spill_5;
							  category = 1;
							  //myfile << mi_cycle << endl;
								//myfile4 << duration_spill << endl;
							  spill_global->Fill();

							}
							else {

							  duration_spill =  duration_spill_6;
							  mi_cycle = 0;
							  category = 1;
							  //myfile << mi_cycle << endl;
								//myfile4 << duration_spill << endl;
							  spill_global->Fill();

							}


		}  // End For the ROOT files 6GeV Neg

		// == 9 GeV Pos

		  for(Int_t i=74+71+74+68+69+74; i<74+71+74+68+69+74+68; i++){ //For() over all the root files
			polarityb = 1;
			energyb = 9;
			cout <<  i ;

				t_begin[i]=0;
				f[i] = (TFile*)gROOT->GetListOfFiles()->FindObject(name_file[i]);

				if (!f[i] || !f[i]->IsOpen()) {
					 f[i] = new TFile(name_file[i],"READ");
				}

				f[i]->GetObject("CAMACTree",tree[i]);
		   	Init(tree[i]);      //fChain equal to the tree corresponding to the array_file_root[i]
		    cout <<  i  << "..." << endl  ;

				//  =============================== LOOP ================================= //
				//  Input: root file of TB with the most importat variable: Spill_number
				//  Loop 0 will record the begining of the time in the root file in order to remove the unix time and use only seconds
				//  Loop 1-6 will get the begining in time for each spill for future uses
				//  Loop 7 : creates the results root file with the spills but now calibrated to the begining of the spill

				// IMPORTANT Values: int jentry_array,jentry_array2,jentry_array3,jentry_array4,jentry_array5,jentry_array6;
					//
					// | ------- | ----- Spill_number == 1 ----- | ----- Spill_number == 2 ----- | ---
					//
					//
					//  A ------- B ---------------------------- C ----------------------------- D ----
					// Variables:
					// A: Time begining of the root file -> t_begin
					// B: Entry in root file for the time begining of Spill_number == 1 -> jentry_array
					// C: Entry in root file for the end begining of Spill_number == 1 -> jentry_array + nentries_1
					// This code can not know the entry for the end of the spill, but we can
					// get it by knowing the total numbers of entries.
					// D: Entry in root file for the time begining of Spill_number == X -> jentry_array_X

					int jentry_array,jentry_array2,jentry_array3,jentry_array4,jentry_array5,jentry_array6;
					Double_t Time_begin_spill_1,Time_begin_spill_2,Time_begin_spill_3,Time_begin_spill_4,Time_begin_spill_5,Time_begin_spill_6;
					Double_t t_o_spill_1, t_o_spill_2, t_o_spill_3, t_o_spill_4, t_o_spill_5, t_o_spill_6;
					Double_t exists_spill_1, exists_spill_2, exists_spill_3, exists_spill_4, exists_spill_5, exists_spill_6;

					exists_spill_1 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 1");
					//myfile3 << "Existe el spill 1?: " << exists_spill_1 << endl;
					exists_spill_2 = fChain->GetEntries("Time && In_spill>0.5  && Spill_number == 2");
					//myfile3 << "Existe el spill 2?: " <<exists_spill_2 << endl;
					exists_spill_3 = fChain->GetEntries("Time && In_spill>0.5  && Spill_number == 3");
					//myfile3 << "Existe el spill 3?: " <<exists_spill_3 << endl;
					exists_spill_4 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 4");
					//myfile3 << "Existe el spill 4?: " <<exists_spill_4 << endl;
					exists_spill_5 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 5");
					//myfile3 << "Existe el spill 5?: " <<exists_spill_5 << endl;
					exists_spill_6 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 6");
					//myfile3 << "Existe el spill 6?: " <<exists_spill_6 << endl;

					// ================= LOOP 0 : Begin of the Variable Time and =================== //

					if (fChain == 0) return; Long64_t nentries = fChain->GetEntries(); Long64_t nbytes = 0, nb = 0;
					Double_t signal1_t_begin_spill_1, signal1_t_begin_spill_2, signal1_t_begin_spill_3, signal1_t_begin_spill_4, signal1_t_begin_spill_5, signal1_t_begin_spill_6;

					signal1_t_begin_spill_1 = 0; 			signal1_t_begin_spill_2 = 0;
					signal1_t_begin_spill_3 = 0;			signal1_t_begin_spill_4 = 0;
					signal1_t_begin_spill_5 = 0;			signal1_t_begin_spill_6 = 0;

					for (Long64_t jentry=0; jentry<1;jentry++) {
							Long64_t ientry = LoadTree(jentry); if (ientry < 0) break;
							nb = fChain->GetEntry(jentry);   nbytes += nb; t_begin[i] = (Double_t) Time;
							//myfile2 << "t_begin: "<< t_begin[i] << endl;
					 }

						// ================= LOOP 1 : Begin Time for the Spill_number == 1 =================== //

					// ================= LOOP 1 : Begin Time for the Spill_number == 1 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
						 Long64_t ientry = LoadTree(jentry);                //if (ientry < 0) break;
						 nb = fChain->GetEntry(jentry);   nbytes += nb;

						 if (In_spill > 0.5 ){if (Spill_number == 1 && exists_spill_1 != 0 ){
							 //jentry_array= (Double_t) jentry;

							Time_begin_spill_1 = (Double_t) Time - t_begin[i];
							t_o_spill_1 = (Double_t) Time;
							signal1_t_begin_spill_1 = 1;
																				break ;                  }                 }             }

					// ================= LOOP 2 : Begin Time for the Spill_number == 2 =================== //

					 for (Long64_t jentry=0; jentry<nentries;jentry++) {
						 Long64_t ientry = LoadTree(jentry);                 //if (ientry < 0) break;
							nb = fChain->GetEntry(jentry);   nbytes += nb;

							if (In_spill > 0.5 ){ if (Spill_number == 2 ){ jentry_array2= (Double_t) jentry;
								Time_begin_spill_2 = (Double_t) Time - t_begin[i];
								t_o_spill_2 = (Double_t) Time;
								////myfile << "jentry_array2: "<< jentry_array2 << endl;
								 //myfile2 << "Time_spill_2 "<< Time_begin_spill_2 << endl;
								 signal1_t_begin_spill_2 = 1;
										break ;                    }                  }              }

					// ================= LOOP 3 : Begin Time for the Spill_number == 3 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
							 Long64_t ientry = LoadTree(jentry);                 //if (ientry < 0) break;
							 nb = fChain->GetEntry(jentry);   nbytes += nb;

							 if (In_spill > 0.5 ){if (Spill_number == 3 ){jentry_array3= (Double_t) jentry;
								Time_begin_spill_3 = (Double_t) Time - t_begin[i];
								t_o_spill_3 = (Double_t) Time;
								 ////myfile << "jentry_array3: "<< jentry_array3 << endl;
								 //myfile2 << "Time_spill_3 "<< Time_begin_spill_3 << endl;
								 signal1_t_begin_spill_3 = 1;
										 break ;                     }                   }               }

					// ================= LOOP 4 : Begin Time for the Spill_number == 4 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
								Long64_t ientry = LoadTree(jentry);
								// if (ientry < 0) break;
								nb = fChain->GetEntry(jentry);   nbytes += nb;

								if (In_spill > 0.5 ){if (Spill_number == 4 ){jentry_array4= (Double_t) jentry;
								Time_begin_spill_4 = (Double_t) Time - t_begin[i];
								t_o_spill_4 = (Double_t) Time;
								 ////myfile << "jentry_array4: "<< jentry_array4 << endl;
								 //myfile2 << "Time_spill_4 "<< Time_begin_spill_4 << endl;
								 signal1_t_begin_spill_4 = 1;
											break ;                      }                    }                }

					// ================= LOOP 5 : Begin Time for the Spill_number == 5 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
								 Long64_t ientry = LoadTree(jentry);
								 //if (ientry < 0) break;
								 nb = fChain->GetEntry(jentry);   nbytes += nb;

								 if (In_spill > 0.5 ){if (Spill_number == 5 ){jentry_array5= (Double_t) jentry;
								Time_begin_spill_5 = (Double_t) Time - t_begin[i];
								t_o_spill_5 = (Double_t) Time;
								 ////myfile << "jentry_array5: "<< jentry_array5 << endl;
								 //myfile2 << "Time_spill_5 "<< Time_begin_spill_5 << endl;
								 signal1_t_begin_spill_5 = 1;
											 break ;                       }                     }                 }

					// ================= LOOP 6 : Begin Time for the Spill_number == 2 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
									Long64_t ientry = LoadTree(jentry);
									//if (ientry < 0) break;
									nb = fChain->GetEntry(jentry);   nbytes += nb;

									if (In_spill > 0.5 ){if (Spill_number == 6 ){jentry_array6= (Double_t) jentry;
								Time_begin_spill_6 = (Double_t) Time - t_begin[i];
								t_o_spill_6 = (Double_t) Time;
								 ////myfile << "jentry_array6: "<< jentry_array6 << endl;
								 //myfile2 << "Time_spill_6 "<< Time_begin_spill_6 << endl;
								 signal1_t_begin_spill_6 = 1;
												break ;                        }                      }                  }

					Float_t interval_between_spills = 0.0;

					if (fChain == 0) return;
					 Long64_t nentries = fChain->GetEntries();
					 Long64_t nbytes = 0, nb = 0;

					 Double_t duration_spill_1, duration_spill_2, duration_spill_3, duration_spill_4, duration_spill_5, duration_spill_6;

					 for (Long64_t jentry=0; jentry<nentries;jentry++) {
						 Long64_t ientry = LoadTree(jentry);
						 //if (ientry < 0) break;
						 nb = fChain->GetEntry(jentry);   nbytes += nb;

							//Conditions for Spill has actual values

							Time_spill_1b = -1; Time_spill_2b = -1; Time_spill_3b = -1;
							Time_spill_4b = -1; Time_spill_5b = -1; Time_spill_6b = -1;
							mi_cycle = 0;

		      	if (In_spill > 0.5 )              {
		          if (Spill_number == 1  )                 {

		                  Time_spill_1 = (Double_t) Time -t_begin[i];
		                  duration_spill_1 = Time_spill_1 - Time_begin_spill_1;

		                  Time_spill_1b = (Double_t) Time - t_o_spill_1;
		                  Spill_numberb = 1;
		                  tree_spill->Fill();


		            }
		            else if (Spill_number == 2 )
		            {
		                  Time_spill_2= (Double_t) Time -t_begin[i];
		                  duration_spill_2 = Time_spill_2 - Time_begin_spill_2;


		                  Time_spill_2b = (Double_t) Time - t_o_spill_2;
		                  Spill_numberb = 2;
		                  tree_spill->Fill();

		            }

		            else if (Spill_number == 3  )
		            {
		                  Time_spill_3= (Double_t) Time -t_begin[i];
		                  duration_spill_3 = Time_spill_3 - Time_begin_spill_3;

		                  Time_spill_3b = (Double_t) Time - t_o_spill_3;
		                  Spill_numberb = 3;
		                  tree_spill->Fill();

		             }

		           else if (Spill_number == 4  )
		           {
		                 Time_spill_4= (Double_t) Time -t_begin[i];
		                 duration_spill_4 = Time_spill_4 - Time_begin_spill_4;


		                 Time_spill_4b = (Double_t) Time - t_o_spill_4 ;
		                 Spill_numberb = 4;
		                 tree_spill->Fill();
		          	}

		          	else if (Spill_number == 5  )
		          	{
		                Time_spill_5= (Double_t) Time -t_begin[i];
		                duration_spill_5 = Time_spill_5 - Time_begin_spill_5;


		                Time_spill_5b = (Double_t) Time - t_o_spill_5 ;
		                Spill_numberb = 5;
		                tree_spill->Fill();
		          	}

		         	 else if (Spill_number == 6  )
		         	 {
		               Time_spill_6= (Double_t) Time -t_begin[i];
		               duration_spill_6 = Time_spill_6 - Time_begin_spill_6;


		               Time_spill_6b = (Double_t) Time - t_o_spill_6;
		               Spill_numberb = 6;
		               tree_spill->Fill();
		         	 }

		        } // end of:  if (In_spill > 0.5 )
		 			}//end of: for (Long64_t jentry=0; jentry<nentries;jentry++)

					  	// ## 1

						  duration_spill =  duration_spill_1;
						  category = 1;
						  mi_cycle = 0;
							//myfile << mi_cycle << endl;
							//myfile4 << duration_spill << endl;
						  spill_global->Fill();

							// ## 2

							if(signal1_t_begin_spill_1 == 1 && signal1_t_begin_spill_2 == 1){

								  duration_spill =  duration_spill_2;
								  mi_cycle = t_o_spill_2 - t_o_spill_1;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

								  duration_spill =  duration_spill_2;
								  mi_cycle = 0;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							// ## 3

							if(signal1_t_begin_spill_3 == 1 && signal1_t_begin_spill_2 == 1){

								  duration_spill =  duration_spill_3;
								  mi_cycle = t_o_spill_3 - t_o_spill_2;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

								  duration_spill =  duration_spill_3;
								  mi_cycle = 0;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}

						  // ## 4
							if(signal1_t_begin_spill_3 == 1 && signal1_t_begin_spill_4 == 1){

								  duration_spill =  duration_spill_4;
								  mi_cycle =  t_o_spill_4 - t_o_spill_3;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

									duration_spill =  duration_spill_4;
								  mi_cycle = 0;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
						  // ## 5

							if(signal1_t_begin_spill_4 == 1 && signal1_t_begin_spill_5 == 1){

								  duration_spill =  duration_spill_5;
								  mi_cycle = t_o_spill_5 - t_o_spill_4;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

							  duration_spill =  duration_spill_5;
							  mi_cycle = 0 ;
							  category = 1;
							  //myfile << mi_cycle << endl;
								//myfile4 << duration_spill << endl;
							  spill_global->Fill();

							}
						  // ## 6

							if(signal1_t_begin_spill_6 == 1 && signal1_t_begin_spill_5 == 1){

							  duration_spill =  duration_spill_6;
							  mi_cycle = t_o_spill_6 - t_o_spill_5;
							  category = 1;
							  //myfile << mi_cycle << endl;
								//myfile4 << duration_spill << endl;
							  spill_global->Fill();

							}
							else {

							  duration_spill =  duration_spill_6;
							  mi_cycle = 0;
							  category = 1;
							  //myfile << mi_cycle << endl;
								//myfile4 << duration_spill << endl;
							  spill_global->Fill();

							}


		}  // End For the ROOT files 9GeV Pos

		// == 10 GeV Pos

		  for(Int_t i=74+71+74+68+69+74+68; i<74+71+74+68+69+74+68+65; i++){ //For() over all the root files
			polarityb = 1;
			energyb = 10;
			cout <<  i ;

				t_begin[i]=0;
				f[i] = (TFile*)gROOT->GetListOfFiles()->FindObject(name_file[i]);

				if (!f[i] || !f[i]->IsOpen()) {
					 f[i] = new TFile(name_file[i],"READ");
				}

				f[i]->GetObject("CAMACTree",tree[i]);
		   	Init(tree[i]);      //fChain equal to the tree corresponding to the array_file_root[i]
		    cout <<  i  << "..." << endl  ;

				//  =============================== LOOP ================================= //
				//  Input: root file of TB with the most importat variable: Spill_number
				//  Loop 0 will record the begining of the time in the root file in order to remove the unix time and use only seconds
				//  Loop 1-6 will get the begining in time for each spill for future uses
				//  Loop 7 : creates the results root file with the spills but now calibrated to the begining of the spill

				// IMPORTANT Values: int jentry_array,jentry_array2,jentry_array3,jentry_array4,jentry_array5,jentry_array6;
					//
					// | ------- | ----- Spill_number == 1 ----- | ----- Spill_number == 2 ----- | ---
					//
					//
					//  A ------- B ---------------------------- C ----------------------------- D ----
					// Variables:
					// A: Time begining of the root file -> t_begin
					// B: Entry in root file for the time begining of Spill_number == 1 -> jentry_array
					// C: Entry in root file for the end begining of Spill_number == 1 -> jentry_array + nentries_1
					// This code can not know the entry for the end of the spill, but we can
					// get it by knowing the total numbers of entries.
					// D: Entry in root file for the time begining of Spill_number == X -> jentry_array_X

					int jentry_array,jentry_array2,jentry_array3,jentry_array4,jentry_array5,jentry_array6;
					Double_t Time_begin_spill_1,Time_begin_spill_2,Time_begin_spill_3,Time_begin_spill_4,Time_begin_spill_5,Time_begin_spill_6;
					Double_t t_o_spill_1, t_o_spill_2, t_o_spill_3, t_o_spill_4, t_o_spill_5, t_o_spill_6;
					Double_t exists_spill_1, exists_spill_2, exists_spill_3, exists_spill_4, exists_spill_5, exists_spill_6;

					exists_spill_1 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 1");
					//myfile3 << "Existe el spill 1?: " << exists_spill_1 << endl;
					exists_spill_2 = fChain->GetEntries("Time && In_spill>0.5  && Spill_number == 2");
					//myfile3 << "Existe el spill 2?: " <<exists_spill_2 << endl;
					exists_spill_3 = fChain->GetEntries("Time && In_spill>0.5  && Spill_number == 3");
					//myfile3 << "Existe el spill 3?: " <<exists_spill_3 << endl;
					exists_spill_4 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 4");
					//myfile3 << "Existe el spill 4?: " <<exists_spill_4 << endl;
					exists_spill_5 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 5");
					//myfile3 << "Existe el spill 5?: " <<exists_spill_5 << endl;
					exists_spill_6 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 6");
					//myfile3 << "Existe el spill 6?: " <<exists_spill_6 << endl;

					// ================= LOOP 0 : Begin of the Variable Time and =================== //

					if (fChain == 0) return; Long64_t nentries = fChain->GetEntries(); Long64_t nbytes = 0, nb = 0;
					Double_t signal1_t_begin_spill_1, signal1_t_begin_spill_2, signal1_t_begin_spill_3, signal1_t_begin_spill_4, signal1_t_begin_spill_5, signal1_t_begin_spill_6;

					signal1_t_begin_spill_1 = 0; 			signal1_t_begin_spill_2 = 0;
					signal1_t_begin_spill_3 = 0;			signal1_t_begin_spill_4 = 0;
					signal1_t_begin_spill_5 = 0;			signal1_t_begin_spill_6 = 0;

					for (Long64_t jentry=0; jentry<1;jentry++) {
							Long64_t ientry = LoadTree(jentry); if (ientry < 0) break;
							nb = fChain->GetEntry(jentry);   nbytes += nb; t_begin[i] = (Double_t) Time;
							//myfile2 << "t_begin: "<< t_begin[i] << endl;
					 }

						// ================= LOOP 1 : Begin Time for the Spill_number == 1 =================== //

					// ================= LOOP 1 : Begin Time for the Spill_number == 1 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
						 Long64_t ientry = LoadTree(jentry);                //if (ientry < 0) break;
						 nb = fChain->GetEntry(jentry);   nbytes += nb;

						 if (In_spill > 0.5 ){if (Spill_number == 1 && exists_spill_1 != 0 ){
							 //jentry_array= (Double_t) jentry;

							Time_begin_spill_1 = (Double_t) Time - t_begin[i];
							t_o_spill_1 = (Double_t) Time;
							signal1_t_begin_spill_1 = 1;
																				break ;                  }                 }             }

					// ================= LOOP 2 : Begin Time for the Spill_number == 2 =================== //

					 for (Long64_t jentry=0; jentry<nentries;jentry++) {
						 Long64_t ientry = LoadTree(jentry);                 //if (ientry < 0) break;
							nb = fChain->GetEntry(jentry);   nbytes += nb;

							if (In_spill > 0.5 ){ if (Spill_number == 2 ){ jentry_array2= (Double_t) jentry;
								Time_begin_spill_2 = (Double_t) Time - t_begin[i];
								t_o_spill_2 = (Double_t) Time;
								////myfile << "jentry_array2: "<< jentry_array2 << endl;
								 //myfile2 << "Time_spill_2 "<< Time_begin_spill_2 << endl;
								 signal1_t_begin_spill_2 = 1;
										break ;                    }                  }              }

					// ================= LOOP 3 : Begin Time for the Spill_number == 3 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
							 Long64_t ientry = LoadTree(jentry);                 //if (ientry < 0) break;
							 nb = fChain->GetEntry(jentry);   nbytes += nb;

							 if (In_spill > 0.5 ){if (Spill_number == 3 ){jentry_array3= (Double_t) jentry;
								Time_begin_spill_3 = (Double_t) Time - t_begin[i];
								t_o_spill_3 = (Double_t) Time;
								 ////myfile << "jentry_array3: "<< jentry_array3 << endl;
								 //myfile2 << "Time_spill_3 "<< Time_begin_spill_3 << endl;
								 signal1_t_begin_spill_3 = 1;
										 break ;                     }                   }               }

					// ================= LOOP 4 : Begin Time for the Spill_number == 4 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
								Long64_t ientry = LoadTree(jentry);
								// if (ientry < 0) break;
								nb = fChain->GetEntry(jentry);   nbytes += nb;

								if (In_spill > 0.5 ){if (Spill_number == 4 ){jentry_array4= (Double_t) jentry;
								Time_begin_spill_4 = (Double_t) Time - t_begin[i];
								t_o_spill_4 = (Double_t) Time;
								 ////myfile << "jentry_array4: "<< jentry_array4 << endl;
								 //myfile2 << "Time_spill_4 "<< Time_begin_spill_4 << endl;
								 signal1_t_begin_spill_4 = 1;
											break ;                      }                    }                }

					// ================= LOOP 5 : Begin Time for the Spill_number == 5 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
								 Long64_t ientry = LoadTree(jentry);
								 //if (ientry < 0) break;
								 nb = fChain->GetEntry(jentry);   nbytes += nb;

								 if (In_spill > 0.5 ){if (Spill_number == 5 ){jentry_array5= (Double_t) jentry;
								Time_begin_spill_5 = (Double_t) Time - t_begin[i];
								t_o_spill_5 = (Double_t) Time;
								 ////myfile << "jentry_array5: "<< jentry_array5 << endl;
								 //myfile2 << "Time_spill_5 "<< Time_begin_spill_5 << endl;
								 signal1_t_begin_spill_5 = 1;
											 break ;                       }                     }                 }

					// ================= LOOP 6 : Begin Time for the Spill_number == 2 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
									Long64_t ientry = LoadTree(jentry);
									//if (ientry < 0) break;
									nb = fChain->GetEntry(jentry);   nbytes += nb;

									if (In_spill > 0.5 ){if (Spill_number == 6 ){jentry_array6= (Double_t) jentry;
								Time_begin_spill_6 = (Double_t) Time - t_begin[i];
								t_o_spill_6 = (Double_t) Time;
								 ////myfile << "jentry_array6: "<< jentry_array6 << endl;
								 //myfile2 << "Time_spill_6 "<< Time_begin_spill_6 << endl;
								 signal1_t_begin_spill_6 = 1;
												break ;                        }                      }                  }

					Float_t interval_between_spills = 0.0;

					if (fChain == 0) return;
					 Long64_t nentries = fChain->GetEntries();
					 Long64_t nbytes = 0, nb = 0;

					 Double_t duration_spill_1, duration_spill_2, duration_spill_3, duration_spill_4, duration_spill_5, duration_spill_6;

					 for (Long64_t jentry=0; jentry<nentries;jentry++) {
						 Long64_t ientry = LoadTree(jentry);
						 //if (ientry < 0) break;
						 nb = fChain->GetEntry(jentry);   nbytes += nb;

							//Conditions for Spill has actual values

							Time_spill_1b = -1; Time_spill_2b = -1; Time_spill_3b = -1;
							Time_spill_4b = -1; Time_spill_5b = -1; Time_spill_6b = -1;
							mi_cycle = 0;

		      	if (In_spill > 0.5 )              {
		          if (Spill_number == 1  )                 {

		                  Time_spill_1 = (Double_t) Time -t_begin[i];
		                  duration_spill_1 = Time_spill_1 - Time_begin_spill_1;

		                  Time_spill_1b = (Double_t) Time - t_o_spill_1;
		                  Spill_numberb = 1;
		                  tree_spill->Fill();


		            }
		            else if (Spill_number == 2 )
		            {
		                  Time_spill_2= (Double_t) Time -t_begin[i];
		                  duration_spill_2 = Time_spill_2 - Time_begin_spill_2;


		                  Time_spill_2b = (Double_t) Time - t_o_spill_2;
		                  Spill_numberb = 2;
		                  tree_spill->Fill();

		            }

		            else if (Spill_number == 3  )
		            {
		                  Time_spill_3= (Double_t) Time -t_begin[i];
		                  duration_spill_3 = Time_spill_3 - Time_begin_spill_3;

		                  Time_spill_3b = (Double_t) Time - t_o_spill_3;
		                  Spill_numberb = 3;
		                  tree_spill->Fill();

		             }

		           else if (Spill_number == 4  )
		           {
		                 Time_spill_4= (Double_t) Time -t_begin[i];
		                 duration_spill_4 = Time_spill_4 - Time_begin_spill_4;


		                 Time_spill_4b = (Double_t) Time - t_o_spill_4 ;
		                 Spill_numberb = 4;
		                 tree_spill->Fill();
		          	}

		          	else if (Spill_number == 5  )
		          	{
		                Time_spill_5= (Double_t) Time -t_begin[i];
		                duration_spill_5 = Time_spill_5 - Time_begin_spill_5;


		                Time_spill_5b = (Double_t) Time - t_o_spill_5 ;
		                Spill_numberb = 5;
		                tree_spill->Fill();
		          	}

		         	 else if (Spill_number == 6  )
		         	 {
		               Time_spill_6= (Double_t) Time -t_begin[i];
		               duration_spill_6 = Time_spill_6 - Time_begin_spill_6;


		               Time_spill_6b = (Double_t) Time - t_o_spill_6;
		               Spill_numberb = 6;
		               tree_spill->Fill();
		         	 }

		        } // end of:  if (In_spill > 0.5 )
		 			}//end of: for (Long64_t jentry=0; jentry<nentries;jentry++)

					  	// ## 1

						  duration_spill =  duration_spill_1;
						  category = 1;
						  mi_cycle = 0;
							//myfile << mi_cycle << endl;
							//myfile4 << duration_spill << endl;
						  spill_global->Fill();

							// ## 2

							if(signal1_t_begin_spill_1 == 1 && signal1_t_begin_spill_2 == 1){

								  duration_spill =  duration_spill_2;
								  mi_cycle = t_o_spill_2 - t_o_spill_1;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

								  duration_spill =  duration_spill_2;
								  mi_cycle = 0;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							// ## 3

							if(signal1_t_begin_spill_3 == 1 && signal1_t_begin_spill_2 == 1){

								  duration_spill =  duration_spill_3;
								  mi_cycle = t_o_spill_3 - t_o_spill_2;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

								  duration_spill =  duration_spill_3;
								  mi_cycle = 0;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}

						  // ## 4
							if(signal1_t_begin_spill_3 == 1 && signal1_t_begin_spill_4 == 1){

								  duration_spill =  duration_spill_4;
								  mi_cycle =  t_o_spill_4 - t_o_spill_3;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

									duration_spill =  duration_spill_4;
								  mi_cycle = 0;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
						  // ## 5

							if(signal1_t_begin_spill_4 == 1 && signal1_t_begin_spill_5 == 1){

								  duration_spill =  duration_spill_5;
								  mi_cycle = t_o_spill_5 - t_o_spill_4;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

							  duration_spill =  duration_spill_5;
							  mi_cycle = 0 ;
							  category = 1;
							  //myfile << mi_cycle << endl;
								//myfile4 << duration_spill << endl;
							  spill_global->Fill();

							}
						  // ## 6

							if(signal1_t_begin_spill_6 == 1 && signal1_t_begin_spill_5 == 1){

							  duration_spill =  duration_spill_6;
							  mi_cycle = t_o_spill_6 - t_o_spill_5;
							  category = 1;
							  //myfile << mi_cycle << endl;
								//myfile4 << duration_spill << endl;
							  spill_global->Fill();

							}
							else {

							  duration_spill =  duration_spill_6;
							  mi_cycle = 0;
							  category = 1;
							  //myfile << mi_cycle << endl;
								//myfile4 << duration_spill << endl;
							  spill_global->Fill();

							}


		}  // End For the ROOT files 9GeV Pos

		// == 16 GeV Pos

		  for(Int_t i=74+71+74+68+69+74+68+65; i<74+71+74+68+69+74+68+65+32; i++){ //For() over all the root files
			polarityb = 1;
			energyb = 16;
			cout <<  i ;

				t_begin[i]=0;
				f[i] = (TFile*)gROOT->GetListOfFiles()->FindObject(name_file[i]);

				if (!f[i] || !f[i]->IsOpen()) {
					 f[i] = new TFile(name_file[i],"READ");
				}

				f[i]->GetObject("CAMACTree",tree[i]);
		   	Init(tree[i]);      //fChain equal to the tree corresponding to the array_file_root[i]
		    cout <<  i  << "..." << endl  ;

				//  =============================== LOOP ================================= //
				//  Input: root file of TB with the most importat variable: Spill_number
				//  Loop 0 will record the begining of the time in the root file in order to remove the unix time and use only seconds
				//  Loop 1-6 will get the begining in time for each spill for future uses
				//  Loop 7 : creates the results root file with the spills but now calibrated to the begining of the spill

				// IMPORTANT Values: int jentry_array,jentry_array2,jentry_array3,jentry_array4,jentry_array5,jentry_array6;
					//
					// | ------- | ----- Spill_number == 1 ----- | ----- Spill_number == 2 ----- | ---
					//
					//
					//  A ------- B ---------------------------- C ----------------------------- D ----
					// Variables:
					// A: Time begining of the root file -> t_begin
					// B: Entry in root file for the time begining of Spill_number == 1 -> jentry_array
					// C: Entry in root file for the end begining of Spill_number == 1 -> jentry_array + nentries_1
					// This code can not know the entry for the end of the spill, but we can
					// get it by knowing the total numbers of entries.
					// D: Entry in root file for the time begining of Spill_number == X -> jentry_array_X

					int jentry_array,jentry_array2,jentry_array3,jentry_array4,jentry_array5,jentry_array6;
					Double_t Time_begin_spill_1,Time_begin_spill_2,Time_begin_spill_3,Time_begin_spill_4,Time_begin_spill_5,Time_begin_spill_6;
					Double_t t_o_spill_1, t_o_spill_2, t_o_spill_3, t_o_spill_4, t_o_spill_5, t_o_spill_6;
					Double_t exists_spill_1, exists_spill_2, exists_spill_3, exists_spill_4, exists_spill_5, exists_spill_6;

					exists_spill_1 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 1");
					//myfile3 << "Existe el spill 1?: " << exists_spill_1 << endl;
					exists_spill_2 = fChain->GetEntries("Time && In_spill>0.5  && Spill_number == 2");
					//myfile3 << "Existe el spill 2?: " <<exists_spill_2 << endl;
					exists_spill_3 = fChain->GetEntries("Time && In_spill>0.5  && Spill_number == 3");
					//myfile3 << "Existe el spill 3?: " <<exists_spill_3 << endl;
					exists_spill_4 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 4");
					//myfile3 << "Existe el spill 4?: " <<exists_spill_4 << endl;
					exists_spill_5 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 5");
					//myfile3 << "Existe el spill 5?: " <<exists_spill_5 << endl;
					exists_spill_6 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 6");
					//myfile3 << "Existe el spill 6?: " <<exists_spill_6 << endl;

					// ================= LOOP 0 : Begin of the Variable Time and =================== //

					if (fChain == 0) return; Long64_t nentries = fChain->GetEntries(); Long64_t nbytes = 0, nb = 0;
					Double_t signal1_t_begin_spill_1, signal1_t_begin_spill_2, signal1_t_begin_spill_3, signal1_t_begin_spill_4, signal1_t_begin_spill_5, signal1_t_begin_spill_6;

					signal1_t_begin_spill_1 = 0; 			signal1_t_begin_spill_2 = 0;
					signal1_t_begin_spill_3 = 0;			signal1_t_begin_spill_4 = 0;
					signal1_t_begin_spill_5 = 0;			signal1_t_begin_spill_6 = 0;

					for (Long64_t jentry=0; jentry<1;jentry++) {
							Long64_t ientry = LoadTree(jentry); if (ientry < 0) break;
							nb = fChain->GetEntry(jentry);   nbytes += nb; t_begin[i] = (Double_t) Time;
							//myfile2 << "t_begin: "<< t_begin[i] << endl;
					 }

						// ================= LOOP 1 : Begin Time for the Spill_number == 1 =================== //

					// ================= LOOP 1 : Begin Time for the Spill_number == 1 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
						 Long64_t ientry = LoadTree(jentry);                //if (ientry < 0) break;
						 nb = fChain->GetEntry(jentry);   nbytes += nb;

						 if (In_spill > 0.5 ){if (Spill_number == 1 && exists_spill_1 != 0 ){
							 //jentry_array= (Double_t) jentry;

							Time_begin_spill_1 = (Double_t) Time - t_begin[i];
							t_o_spill_1 = (Double_t) Time;
							signal1_t_begin_spill_1 = 1;
																				break ;                  }                 }             }

					// ================= LOOP 2 : Begin Time for the Spill_number == 2 =================== //

					 for (Long64_t jentry=0; jentry<nentries;jentry++) {
						 Long64_t ientry = LoadTree(jentry);                 //if (ientry < 0) break;
							nb = fChain->GetEntry(jentry);   nbytes += nb;

							if (In_spill > 0.5 ){ if (Spill_number == 2 ){ jentry_array2= (Double_t) jentry;
								Time_begin_spill_2 = (Double_t) Time - t_begin[i];
								t_o_spill_2 = (Double_t) Time;
								////myfile << "jentry_array2: "<< jentry_array2 << endl;
								 //myfile2 << "Time_spill_2 "<< Time_begin_spill_2 << endl;
								 signal1_t_begin_spill_2 = 1;
										break ;                    }                  }              }

					// ================= LOOP 3 : Begin Time for the Spill_number == 3 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
							 Long64_t ientry = LoadTree(jentry);                 //if (ientry < 0) break;
							 nb = fChain->GetEntry(jentry);   nbytes += nb;

							 if (In_spill > 0.5 ){if (Spill_number == 3 ){jentry_array3= (Double_t) jentry;
								Time_begin_spill_3 = (Double_t) Time - t_begin[i];
								t_o_spill_3 = (Double_t) Time;
								 ////myfile << "jentry_array3: "<< jentry_array3 << endl;
								 //myfile2 << "Time_spill_3 "<< Time_begin_spill_3 << endl;
								 signal1_t_begin_spill_3 = 1;
										 break ;                     }                   }               }

					// ================= LOOP 4 : Begin Time for the Spill_number == 4 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
								Long64_t ientry = LoadTree(jentry);
								// if (ientry < 0) break;
								nb = fChain->GetEntry(jentry);   nbytes += nb;

								if (In_spill > 0.5 ){if (Spill_number == 4 ){jentry_array4= (Double_t) jentry;
								Time_begin_spill_4 = (Double_t) Time - t_begin[i];
								t_o_spill_4 = (Double_t) Time;
								 ////myfile << "jentry_array4: "<< jentry_array4 << endl;
								 //myfile2 << "Time_spill_4 "<< Time_begin_spill_4 << endl;
								 signal1_t_begin_spill_4 = 1;
											break ;                      }                    }                }

					// ================= LOOP 5 : Begin Time for the Spill_number == 5 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
								 Long64_t ientry = LoadTree(jentry);
								 //if (ientry < 0) break;
								 nb = fChain->GetEntry(jentry);   nbytes += nb;

								 if (In_spill > 0.5 ){if (Spill_number == 5 ){jentry_array5= (Double_t) jentry;
								Time_begin_spill_5 = (Double_t) Time - t_begin[i];
								t_o_spill_5 = (Double_t) Time;
								 ////myfile << "jentry_array5: "<< jentry_array5 << endl;
								 //myfile2 << "Time_spill_5 "<< Time_begin_spill_5 << endl;
								 signal1_t_begin_spill_5 = 1;
											 break ;                       }                     }                 }

					// ================= LOOP 6 : Begin Time for the Spill_number == 2 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
									Long64_t ientry = LoadTree(jentry);
									//if (ientry < 0) break;
									nb = fChain->GetEntry(jentry);   nbytes += nb;

									if (In_spill > 0.5 ){if (Spill_number == 6 ){jentry_array6= (Double_t) jentry;
								Time_begin_spill_6 = (Double_t) Time - t_begin[i];
								t_o_spill_6 = (Double_t) Time;
								 ////myfile << "jentry_array6: "<< jentry_array6 << endl;
								 //myfile2 << "Time_spill_6 "<< Time_begin_spill_6 << endl;
								 signal1_t_begin_spill_6 = 1;
												break ;                        }                      }                  }

					Float_t interval_between_spills = 0.0;

					if (fChain == 0) return;
					 Long64_t nentries = fChain->GetEntries();
					 Long64_t nbytes = 0, nb = 0;

					 Double_t duration_spill_1, duration_spill_2, duration_spill_3, duration_spill_4, duration_spill_5, duration_spill_6;

					 for (Long64_t jentry=0; jentry<nentries;jentry++) {
						 Long64_t ientry = LoadTree(jentry);
						 //if (ientry < 0) break;
						 nb = fChain->GetEntry(jentry);   nbytes += nb;

							//Conditions for Spill has actual values

							Time_spill_1b = -1; Time_spill_2b = -1; Time_spill_3b = -1;
							Time_spill_4b = -1; Time_spill_5b = -1; Time_spill_6b = -1;
							mi_cycle = 0;

		      	if (In_spill > 0.5 )              {
		          if (Spill_number == 1  )                 {

		                  Time_spill_1 = (Double_t) Time -t_begin[i];
		                  duration_spill_1 = Time_spill_1 - Time_begin_spill_1;

		                  Time_spill_1b = (Double_t) Time - t_o_spill_1;
		                  Spill_numberb = 1;
		                  tree_spill->Fill();


		            }
		            else if (Spill_number == 2 )
		            {
		                  Time_spill_2= (Double_t) Time -t_begin[i];
		                  duration_spill_2 = Time_spill_2 - Time_begin_spill_2;


		                  Time_spill_2b = (Double_t) Time - t_o_spill_2;
		                  Spill_numberb = 2;
		                  tree_spill->Fill();

		            }

		            else if (Spill_number == 3  )
		            {
		                  Time_spill_3= (Double_t) Time -t_begin[i];
		                  duration_spill_3 = Time_spill_3 - Time_begin_spill_3;

		                  Time_spill_3b = (Double_t) Time - t_o_spill_3;
		                  Spill_numberb = 3;
		                  tree_spill->Fill();

		             }

		           else if (Spill_number == 4  )
		           {
		                 Time_spill_4= (Double_t) Time -t_begin[i];
		                 duration_spill_4 = Time_spill_4 - Time_begin_spill_4;


		                 Time_spill_4b = (Double_t) Time - t_o_spill_4 ;
		                 Spill_numberb = 4;
		                 tree_spill->Fill();
		          	}

		          	else if (Spill_number == 5  )
		          	{
		                Time_spill_5= (Double_t) Time -t_begin[i];
		                duration_spill_5 = Time_spill_5 - Time_begin_spill_5;


		                Time_spill_5b = (Double_t) Time - t_o_spill_5 ;
		                Spill_numberb = 5;
		                tree_spill->Fill();
		          	}

		         	 else if (Spill_number == 6  )
		         	 {
		               Time_spill_6= (Double_t) Time -t_begin[i];
		               duration_spill_6 = Time_spill_6 - Time_begin_spill_6;


		               Time_spill_6b = (Double_t) Time - t_o_spill_6;
		               Spill_numberb = 6;
		               tree_spill->Fill();
		         	 }

		        } // end of:  if (In_spill > 0.5 )
		 			}//end of: for (Long64_t jentry=0; jentry<nentries;jentry++)

					  	// ## 1

						  duration_spill =  duration_spill_1;
						  category = 1;
						  mi_cycle = 0;
							//myfile << mi_cycle << endl;
							//myfile4 << duration_spill << endl;
						  spill_global->Fill();

							// ## 2

							if(signal1_t_begin_spill_1 == 1 && signal1_t_begin_spill_2 == 1){

								  duration_spill =  duration_spill_2;
								  mi_cycle = t_o_spill_2 - t_o_spill_1;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

								  duration_spill =  duration_spill_2;
								  mi_cycle = 0;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							// ## 3

							if(signal1_t_begin_spill_3 == 1 && signal1_t_begin_spill_2 == 1){

								  duration_spill =  duration_spill_3;
								  mi_cycle = t_o_spill_3 - t_o_spill_2;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

								  duration_spill =  duration_spill_3;
								  mi_cycle = 0;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}

						  // ## 4
							if(signal1_t_begin_spill_3 == 1 && signal1_t_begin_spill_4 == 1){

								  duration_spill =  duration_spill_4;
								  mi_cycle =  t_o_spill_4 - t_o_spill_3;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

									duration_spill =  duration_spill_4;
								  mi_cycle = 0;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
						  // ## 5

							if(signal1_t_begin_spill_4 == 1 && signal1_t_begin_spill_5 == 1){

								  duration_spill =  duration_spill_5;
								  mi_cycle = t_o_spill_5 - t_o_spill_4;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

							  duration_spill =  duration_spill_5;
							  mi_cycle = 0 ;
							  category = 1;
							  //myfile << mi_cycle << endl;
								//myfile4 << duration_spill << endl;
							  spill_global->Fill();

							}
						  // ## 6

							if(signal1_t_begin_spill_6 == 1 && signal1_t_begin_spill_5 == 1){

							  duration_spill =  duration_spill_6;
							  mi_cycle = t_o_spill_6 - t_o_spill_5;
							  category = 1;
							  //myfile << mi_cycle << endl;
								//myfile4 << duration_spill << endl;
							  spill_global->Fill();

							}
							else {

							  duration_spill =  duration_spill_6;
							  mi_cycle = 0;
							  category = 1;
							  //myfile << mi_cycle << endl;
								//myfile4 << duration_spill << endl;
							  spill_global->Fill();

							}


		}  // End For the ROOT files 16GeV Pos

		// == 9 GeV Pos

		  for(Int_t i=74+71+74+68+69+74+68+65+32; i<74+71+74+68+69+74+68+65+32+65; i++){ //For() over all the root files
			polarityb = -1;
			energyb = 9;
			cout <<  i ;

				t_begin[i]=0;
				f[i] = (TFile*)gROOT->GetListOfFiles()->FindObject(name_file[i]);

				if (!f[i] || !f[i]->IsOpen()) {
					 f[i] = new TFile(name_file[i],"READ");
				}

				f[i]->GetObject("CAMACTree",tree[i]);
		   	Init(tree[i]);      //fChain equal to the tree corresponding to the array_file_root[i]
		    cout <<  i  << "..." << endl  ;

				//  =============================== LOOP ================================= //
				//  Input: root file of TB with the most importat variable: Spill_number
				//  Loop 0 will record the begining of the time in the root file in order to remove the unix time and use only seconds
				//  Loop 1-6 will get the begining in time for each spill for future uses
				//  Loop 7 : creates the results root file with the spills but now calibrated to the begining of the spill

				// IMPORTANT Values: int jentry_array,jentry_array2,jentry_array3,jentry_array4,jentry_array5,jentry_array6;
					//
					// | ------- | ----- Spill_number == 1 ----- | ----- Spill_number == 2 ----- | ---
					//
					//
					//  A ------- B ---------------------------- C ----------------------------- D ----
					// Variables:
					// A: Time begining of the root file -> t_begin
					// B: Entry in root file for the time begining of Spill_number == 1 -> jentry_array
					// C: Entry in root file for the end begining of Spill_number == 1 -> jentry_array + nentries_1
					// This code can not know the entry for the end of the spill, but we can
					// get it by knowing the total numbers of entries.
					// D: Entry in root file for the time begining of Spill_number == X -> jentry_array_X

					int jentry_array,jentry_array2,jentry_array3,jentry_array4,jentry_array5,jentry_array6;
					Double_t Time_begin_spill_1,Time_begin_spill_2,Time_begin_spill_3,Time_begin_spill_4,Time_begin_spill_5,Time_begin_spill_6;
					Double_t t_o_spill_1, t_o_spill_2, t_o_spill_3, t_o_spill_4, t_o_spill_5, t_o_spill_6;
					Double_t exists_spill_1, exists_spill_2, exists_spill_3, exists_spill_4, exists_spill_5, exists_spill_6;

					exists_spill_1 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 1");
					//myfile3 << "Existe el spill 1?: " << exists_spill_1 << endl;
					exists_spill_2 = fChain->GetEntries("Time && In_spill>0.5  && Spill_number == 2");
					//myfile3 << "Existe el spill 2?: " <<exists_spill_2 << endl;
					exists_spill_3 = fChain->GetEntries("Time && In_spill>0.5  && Spill_number == 3");
					//myfile3 << "Existe el spill 3?: " <<exists_spill_3 << endl;
					exists_spill_4 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 4");
					//myfile3 << "Existe el spill 4?: " <<exists_spill_4 << endl;
					exists_spill_5 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 5");
					//myfile3 << "Existe el spill 5?: " <<exists_spill_5 << endl;
					exists_spill_6 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 6");
					//myfile3 << "Existe el spill 6?: " <<exists_spill_6 << endl;

					// ================= LOOP 0 : Begin of the Variable Time and =================== //

					if (fChain == 0) return; Long64_t nentries = fChain->GetEntries(); Long64_t nbytes = 0, nb = 0;
					Double_t signal1_t_begin_spill_1, signal1_t_begin_spill_2, signal1_t_begin_spill_3, signal1_t_begin_spill_4, signal1_t_begin_spill_5, signal1_t_begin_spill_6;

					signal1_t_begin_spill_1 = 0; 			signal1_t_begin_spill_2 = 0;
					signal1_t_begin_spill_3 = 0;			signal1_t_begin_spill_4 = 0;
					signal1_t_begin_spill_5 = 0;			signal1_t_begin_spill_6 = 0;

					for (Long64_t jentry=0; jentry<1;jentry++) {
							Long64_t ientry = LoadTree(jentry); if (ientry < 0) break;
							nb = fChain->GetEntry(jentry);   nbytes += nb; t_begin[i] = (Double_t) Time;
							//myfile2 << "t_begin: "<< t_begin[i] << endl;
					 }

						// ================= LOOP 1 : Begin Time for the Spill_number == 1 =================== //

					// ================= LOOP 1 : Begin Time for the Spill_number == 1 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
						 Long64_t ientry = LoadTree(jentry);                //if (ientry < 0) break;
						 nb = fChain->GetEntry(jentry);   nbytes += nb;

						 if (In_spill > 0.5 ){if (Spill_number == 1 && exists_spill_1 != 0 ){
							 //jentry_array= (Double_t) jentry;

							Time_begin_spill_1 = (Double_t) Time - t_begin[i];
							t_o_spill_1 = (Double_t) Time;
							signal1_t_begin_spill_1 = 1;
																				break ;                  }                 }             }

					// ================= LOOP 2 : Begin Time for the Spill_number == 2 =================== //

					 for (Long64_t jentry=0; jentry<nentries;jentry++) {
						 Long64_t ientry = LoadTree(jentry);                 //if (ientry < 0) break;
							nb = fChain->GetEntry(jentry);   nbytes += nb;

							if (In_spill > 0.5 ){ if (Spill_number == 2 ){ jentry_array2= (Double_t) jentry;
								Time_begin_spill_2 = (Double_t) Time - t_begin[i];
								t_o_spill_2 = (Double_t) Time;
								////myfile << "jentry_array2: "<< jentry_array2 << endl;
								 //myfile2 << "Time_spill_2 "<< Time_begin_spill_2 << endl;
								 signal1_t_begin_spill_2 = 1;
										break ;                    }                  }              }

					// ================= LOOP 3 : Begin Time for the Spill_number == 3 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
							 Long64_t ientry = LoadTree(jentry);                 //if (ientry < 0) break;
							 nb = fChain->GetEntry(jentry);   nbytes += nb;

							 if (In_spill > 0.5 ){if (Spill_number == 3 ){jentry_array3= (Double_t) jentry;
								Time_begin_spill_3 = (Double_t) Time - t_begin[i];
								t_o_spill_3 = (Double_t) Time;
								 ////myfile << "jentry_array3: "<< jentry_array3 << endl;
								 //myfile2 << "Time_spill_3 "<< Time_begin_spill_3 << endl;
								 signal1_t_begin_spill_3 = 1;
										 break ;                     }                   }               }

					// ================= LOOP 4 : Begin Time for the Spill_number == 4 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
								Long64_t ientry = LoadTree(jentry);
								// if (ientry < 0) break;
								nb = fChain->GetEntry(jentry);   nbytes += nb;

								if (In_spill > 0.5 ){if (Spill_number == 4 ){jentry_array4= (Double_t) jentry;
								Time_begin_spill_4 = (Double_t) Time - t_begin[i];
								t_o_spill_4 = (Double_t) Time;
								 ////myfile << "jentry_array4: "<< jentry_array4 << endl;
								 //myfile2 << "Time_spill_4 "<< Time_begin_spill_4 << endl;
								 signal1_t_begin_spill_4 = 1;
											break ;                      }                    }                }

					// ================= LOOP 5 : Begin Time for the Spill_number == 5 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
								 Long64_t ientry = LoadTree(jentry);
								 //if (ientry < 0) break;
								 nb = fChain->GetEntry(jentry);   nbytes += nb;

								 if (In_spill > 0.5 ){if (Spill_number == 5 ){jentry_array5= (Double_t) jentry;
								Time_begin_spill_5 = (Double_t) Time - t_begin[i];
								t_o_spill_5 = (Double_t) Time;
								 ////myfile << "jentry_array5: "<< jentry_array5 << endl;
								 //myfile2 << "Time_spill_5 "<< Time_begin_spill_5 << endl;
								 signal1_t_begin_spill_5 = 1;
											 break ;                       }                     }                 }

					// ================= LOOP 6 : Begin Time for the Spill_number == 2 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
									Long64_t ientry = LoadTree(jentry);
									//if (ientry < 0) break;
									nb = fChain->GetEntry(jentry);   nbytes += nb;

									if (In_spill > 0.5 ){if (Spill_number == 6 ){jentry_array6= (Double_t) jentry;
								Time_begin_spill_6 = (Double_t) Time - t_begin[i];
								t_o_spill_6 = (Double_t) Time;
								 ////myfile << "jentry_array6: "<< jentry_array6 << endl;
								 //myfile2 << "Time_spill_6 "<< Time_begin_spill_6 << endl;
								 signal1_t_begin_spill_6 = 1;
												break ;                        }                      }                  }

					Float_t interval_between_spills = 0.0;

					if (fChain == 0) return;
					 Long64_t nentries = fChain->GetEntries();
					 Long64_t nbytes = 0, nb = 0;

					 Double_t duration_spill_1, duration_spill_2, duration_spill_3, duration_spill_4, duration_spill_5, duration_spill_6;

					 for (Long64_t jentry=0; jentry<nentries;jentry++) {
						 Long64_t ientry = LoadTree(jentry);
						 //if (ientry < 0) break;
						 nb = fChain->GetEntry(jentry);   nbytes += nb;

							//Conditions for Spill has actual values

							Time_spill_1b = -1; Time_spill_2b = -1; Time_spill_3b = -1;
							Time_spill_4b = -1; Time_spill_5b = -1; Time_spill_6b = -1;
							mi_cycle = 0;

		      	if (In_spill > 0.5 )              {
		          if (Spill_number == 1  )                 {

		                  Time_spill_1 = (Double_t) Time -t_begin[i];
		                  duration_spill_1 = Time_spill_1 - Time_begin_spill_1;

		                  Time_spill_1b = (Double_t) Time - t_o_spill_1;
		                  Spill_numberb = 1;
		                  tree_spill->Fill();


		            }
		            else if (Spill_number == 2 )
		            {
		                  Time_spill_2= (Double_t) Time -t_begin[i];
		                  duration_spill_2 = Time_spill_2 - Time_begin_spill_2;


		                  Time_spill_2b = (Double_t) Time - t_o_spill_2;
		                  Spill_numberb = 2;
		                  tree_spill->Fill();

		            }

		            else if (Spill_number == 3  )
		            {
		                  Time_spill_3= (Double_t) Time -t_begin[i];
		                  duration_spill_3 = Time_spill_3 - Time_begin_spill_3;

		                  Time_spill_3b = (Double_t) Time - t_o_spill_3;
		                  Spill_numberb = 3;
		                  tree_spill->Fill();

		             }

		           else if (Spill_number == 4  )
		           {
		                 Time_spill_4= (Double_t) Time -t_begin[i];
		                 duration_spill_4 = Time_spill_4 - Time_begin_spill_4;


		                 Time_spill_4b = (Double_t) Time - t_o_spill_4 ;
		                 Spill_numberb = 4;
		                 tree_spill->Fill();
		          	}

		          	else if (Spill_number == 5  )
		          	{
		                Time_spill_5= (Double_t) Time -t_begin[i];
		                duration_spill_5 = Time_spill_5 - Time_begin_spill_5;


		                Time_spill_5b = (Double_t) Time - t_o_spill_5 ;
		                Spill_numberb = 5;
		                tree_spill->Fill();
		          	}

		         	 else if (Spill_number == 6  )
		         	 {
		               Time_spill_6= (Double_t) Time -t_begin[i];
		               duration_spill_6 = Time_spill_6 - Time_begin_spill_6;


		               Time_spill_6b = (Double_t) Time - t_o_spill_6;
		               Spill_numberb = 6;
		               tree_spill->Fill();
		         	 }

		        } // end of:  if (In_spill > 0.5 )
		 			}//end of: for (Long64_t jentry=0; jentry<nentries;jentry++)

					  	// ## 1

						  duration_spill =  duration_spill_1;
						  category = 1;
						  mi_cycle = 0;
							//myfile << mi_cycle << endl;
							//myfile4 << duration_spill << endl;
						  spill_global->Fill();

							// ## 2

							if(signal1_t_begin_spill_1 == 1 && signal1_t_begin_spill_2 == 1){

								  duration_spill =  duration_spill_2;
								  mi_cycle = t_o_spill_2 - t_o_spill_1;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

								  duration_spill =  duration_spill_2;
								  mi_cycle = 0;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							// ## 3

							if(signal1_t_begin_spill_3 == 1 && signal1_t_begin_spill_2 == 1){

								  duration_spill =  duration_spill_3;
								  mi_cycle = t_o_spill_3 - t_o_spill_2;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

								  duration_spill =  duration_spill_3;
								  mi_cycle = 0;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}

						  // ## 4
							if(signal1_t_begin_spill_3 == 1 && signal1_t_begin_spill_4 == 1){

								  duration_spill =  duration_spill_4;
								  mi_cycle =  t_o_spill_4 - t_o_spill_3;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

									duration_spill =  duration_spill_4;
								  mi_cycle = 0;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
						  // ## 5

							if(signal1_t_begin_spill_4 == 1 && signal1_t_begin_spill_5 == 1){

								  duration_spill =  duration_spill_5;
								  mi_cycle = t_o_spill_5 - t_o_spill_4;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

							  duration_spill =  duration_spill_5;
							  mi_cycle = 0 ;
							  category = 1;
							  //myfile << mi_cycle << endl;
								//myfile4 << duration_spill << endl;
							  spill_global->Fill();

							}
						  // ## 6

							if(signal1_t_begin_spill_6 == 1 && signal1_t_begin_spill_5 == 1){

							  duration_spill =  duration_spill_6;
							  mi_cycle = t_o_spill_6 - t_o_spill_5;
							  category = 1;
							  //myfile << mi_cycle << endl;
								//myfile4 << duration_spill << endl;
							  spill_global->Fill();

							}
							else {

							  duration_spill =  duration_spill_6;
							  mi_cycle = 0;
							  category = 1;
							  //myfile << mi_cycle << endl;
								//myfile4 << duration_spill << endl;
							  spill_global->Fill();

							}


		}  // End For the ROOT files 9GeV Neg


		// == 10 GeV Neg

		  for(Int_t i=74+71+74+68+69+74+68+65+32; i<74+71+74+68+69+74+68+65+32+65; i++){ //For() over all the root files
			polarityb = -1;
			energyb = 10;
			cout <<  i ;

				t_begin[i]=0;
				f[i] = (TFile*)gROOT->GetListOfFiles()->FindObject(name_file[i]);

				if (!f[i] || !f[i]->IsOpen()) {
					 f[i] = new TFile(name_file[i],"READ");
				}

				f[i]->GetObject("CAMACTree",tree[i]);
		   	Init(tree[i]);      //fChain equal to the tree corresponding to the array_file_root[i]
		    cout <<  i  << "..." << endl  ;

				//  =============================== LOOP ================================= //
				//  Input: root file of TB with the most importat variable: Spill_number
				//  Loop 0 will record the begining of the time in the root file in order to remove the unix time and use only seconds
				//  Loop 1-6 will get the begining in time for each spill for future uses
				//  Loop 7 : creates the results root file with the spills but now calibrated to the begining of the spill

				// IMPORTANT Values: int jentry_array,jentry_array2,jentry_array3,jentry_array4,jentry_array5,jentry_array6;
					//
					// | ------- | ----- Spill_number == 1 ----- | ----- Spill_number == 2 ----- | ---
					//
					//
					//  A ------- B ---------------------------- C ----------------------------- D ----
					// Variables:
					// A: Time begining of the root file -> t_begin
					// B: Entry in root file for the time begining of Spill_number == 1 -> jentry_array
					// C: Entry in root file for the end begining of Spill_number == 1 -> jentry_array + nentries_1
					// This code can not know the entry for the end of the spill, but we can
					// get it by knowing the total numbers of entries.
					// D: Entry in root file for the time begining of Spill_number == X -> jentry_array_X

					int jentry_array,jentry_array2,jentry_array3,jentry_array4,jentry_array5,jentry_array6;
					Double_t Time_begin_spill_1,Time_begin_spill_2,Time_begin_spill_3,Time_begin_spill_4,Time_begin_spill_5,Time_begin_spill_6;
					Double_t t_o_spill_1, t_o_spill_2, t_o_spill_3, t_o_spill_4, t_o_spill_5, t_o_spill_6;
					Double_t exists_spill_1, exists_spill_2, exists_spill_3, exists_spill_4, exists_spill_5, exists_spill_6;

					exists_spill_1 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 1");
					//myfile3 << "Existe el spill 1?: " << exists_spill_1 << endl;
					exists_spill_2 = fChain->GetEntries("Time && In_spill>0.5  && Spill_number == 2");
					//myfile3 << "Existe el spill 2?: " <<exists_spill_2 << endl;
					exists_spill_3 = fChain->GetEntries("Time && In_spill>0.5  && Spill_number == 3");
					//myfile3 << "Existe el spill 3?: " <<exists_spill_3 << endl;
					exists_spill_4 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 4");
					//myfile3 << "Existe el spill 4?: " <<exists_spill_4 << endl;
					exists_spill_5 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 5");
					//myfile3 << "Existe el spill 5?: " <<exists_spill_5 << endl;
					exists_spill_6 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 6");
					//myfile3 << "Existe el spill 6?: " <<exists_spill_6 << endl;

					// ================= LOOP 0 : Begin of the Variable Time and =================== //

					if (fChain == 0) return; Long64_t nentries = fChain->GetEntries(); Long64_t nbytes = 0, nb = 0;
					Double_t signal1_t_begin_spill_1, signal1_t_begin_spill_2, signal1_t_begin_spill_3, signal1_t_begin_spill_4, signal1_t_begin_spill_5, signal1_t_begin_spill_6;

					signal1_t_begin_spill_1 = 0; 			signal1_t_begin_spill_2 = 0;
					signal1_t_begin_spill_3 = 0;			signal1_t_begin_spill_4 = 0;
					signal1_t_begin_spill_5 = 0;			signal1_t_begin_spill_6 = 0;

					for (Long64_t jentry=0; jentry<1;jentry++) {
							Long64_t ientry = LoadTree(jentry); if (ientry < 0) break;
							nb = fChain->GetEntry(jentry);   nbytes += nb; t_begin[i] = (Double_t) Time;
							//myfile2 << "t_begin: "<< t_begin[i] << endl;
					 }

						// ================= LOOP 1 : Begin Time for the Spill_number == 1 =================== //

					// ================= LOOP 1 : Begin Time for the Spill_number == 1 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
						 Long64_t ientry = LoadTree(jentry);                //if (ientry < 0) break;
						 nb = fChain->GetEntry(jentry);   nbytes += nb;

						 if (In_spill > 0.5 ){if (Spill_number == 1 && exists_spill_1 != 0 ){
							 //jentry_array= (Double_t) jentry;

							Time_begin_spill_1 = (Double_t) Time - t_begin[i];
							t_o_spill_1 = (Double_t) Time;
							signal1_t_begin_spill_1 = 1;
																				break ;                  }                 }             }

					// ================= LOOP 2 : Begin Time for the Spill_number == 2 =================== //

					 for (Long64_t jentry=0; jentry<nentries;jentry++) {
						 Long64_t ientry = LoadTree(jentry);                 //if (ientry < 0) break;
							nb = fChain->GetEntry(jentry);   nbytes += nb;

							if (In_spill > 0.5 ){ if (Spill_number == 2 ){ jentry_array2= (Double_t) jentry;
								Time_begin_spill_2 = (Double_t) Time - t_begin[i];
								t_o_spill_2 = (Double_t) Time;
								////myfile << "jentry_array2: "<< jentry_array2 << endl;
								 //myfile2 << "Time_spill_2 "<< Time_begin_spill_2 << endl;
								 signal1_t_begin_spill_2 = 1;
										break ;                    }                  }              }

					// ================= LOOP 3 : Begin Time for the Spill_number == 3 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
							 Long64_t ientry = LoadTree(jentry);                 //if (ientry < 0) break;
							 nb = fChain->GetEntry(jentry);   nbytes += nb;

							 if (In_spill > 0.5 ){if (Spill_number == 3 ){jentry_array3= (Double_t) jentry;
								Time_begin_spill_3 = (Double_t) Time - t_begin[i];
								t_o_spill_3 = (Double_t) Time;
								 ////myfile << "jentry_array3: "<< jentry_array3 << endl;
								 //myfile2 << "Time_spill_3 "<< Time_begin_spill_3 << endl;
								 signal1_t_begin_spill_3 = 1;
										 break ;                     }                   }               }

					// ================= LOOP 4 : Begin Time for the Spill_number == 4 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
								Long64_t ientry = LoadTree(jentry);
								// if (ientry < 0) break;
								nb = fChain->GetEntry(jentry);   nbytes += nb;

								if (In_spill > 0.5 ){if (Spill_number == 4 ){jentry_array4= (Double_t) jentry;
								Time_begin_spill_4 = (Double_t) Time - t_begin[i];
								t_o_spill_4 = (Double_t) Time;
								 ////myfile << "jentry_array4: "<< jentry_array4 << endl;
								 //myfile2 << "Time_spill_4 "<< Time_begin_spill_4 << endl;
								 signal1_t_begin_spill_4 = 1;
											break ;                      }                    }                }

					// ================= LOOP 5 : Begin Time for the Spill_number == 5 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
								 Long64_t ientry = LoadTree(jentry);
								 //if (ientry < 0) break;
								 nb = fChain->GetEntry(jentry);   nbytes += nb;

								 if (In_spill > 0.5 ){if (Spill_number == 5 ){jentry_array5= (Double_t) jentry;
								Time_begin_spill_5 = (Double_t) Time - t_begin[i];
								t_o_spill_5 = (Double_t) Time;
								 ////myfile << "jentry_array5: "<< jentry_array5 << endl;
								 //myfile2 << "Time_spill_5 "<< Time_begin_spill_5 << endl;
								 signal1_t_begin_spill_5 = 1;
											 break ;                       }                     }                 }

					// ================= LOOP 6 : Begin Time for the Spill_number == 2 =================== //

					for (Long64_t jentry=0; jentry<nentries;jentry++) {
									Long64_t ientry = LoadTree(jentry);
									//if (ientry < 0) break;
									nb = fChain->GetEntry(jentry);   nbytes += nb;

									if (In_spill > 0.5 ){if (Spill_number == 6 ){jentry_array6= (Double_t) jentry;
								Time_begin_spill_6 = (Double_t) Time - t_begin[i];
								t_o_spill_6 = (Double_t) Time;
								 ////myfile << "jentry_array6: "<< jentry_array6 << endl;
								 //myfile2 << "Time_spill_6 "<< Time_begin_spill_6 << endl;
								 signal1_t_begin_spill_6 = 1;
												break ;                        }                      }                  }

					Float_t interval_between_spills = 0.0;

					if (fChain == 0) return;
					 Long64_t nentries = fChain->GetEntries();
					 Long64_t nbytes = 0, nb = 0;

					 Double_t duration_spill_1, duration_spill_2, duration_spill_3, duration_spill_4, duration_spill_5, duration_spill_6;

					 for (Long64_t jentry=0; jentry<nentries;jentry++) {
						 Long64_t ientry = LoadTree(jentry);
						 //if (ientry < 0) break;
						 nb = fChain->GetEntry(jentry);   nbytes += nb;

							//Conditions for Spill has actual values

							Time_spill_1b = -1; Time_spill_2b = -1; Time_spill_3b = -1;
							Time_spill_4b = -1; Time_spill_5b = -1; Time_spill_6b = -1;
							mi_cycle = 0;

		      	if (In_spill > 0.5 )              {
		          if (Spill_number == 1  )                 {

		                  Time_spill_1 = (Double_t) Time -t_begin[i];
		                  duration_spill_1 = Time_spill_1 - Time_begin_spill_1;

		                  Time_spill_1b = (Double_t) Time - t_o_spill_1;
		                  Spill_numberb = 1;
		                  tree_spill->Fill();


		            }
		            else if (Spill_number == 2 )
		            {
		                  Time_spill_2= (Double_t) Time -t_begin[i];
		                  duration_spill_2 = Time_spill_2 - Time_begin_spill_2;


		                  Time_spill_2b = (Double_t) Time - t_o_spill_2;
		                  Spill_numberb = 2;
		                  tree_spill->Fill();

		            }

		            else if (Spill_number == 3  )
		            {
		                  Time_spill_3= (Double_t) Time -t_begin[i];
		                  duration_spill_3 = Time_spill_3 - Time_begin_spill_3;

		                  Time_spill_3b = (Double_t) Time - t_o_spill_3;
		                  Spill_numberb = 3;
		                  tree_spill->Fill();

		             }

		           else if (Spill_number == 4  )
		           {
		                 Time_spill_4= (Double_t) Time -t_begin[i];
		                 duration_spill_4 = Time_spill_4 - Time_begin_spill_4;


		                 Time_spill_4b = (Double_t) Time - t_o_spill_4 ;
		                 Spill_numberb = 4;
		                 tree_spill->Fill();
		          	}

		          	else if (Spill_number == 5  )
		          	{
		                Time_spill_5= (Double_t) Time -t_begin[i];
		                duration_spill_5 = Time_spill_5 - Time_begin_spill_5;


		                Time_spill_5b = (Double_t) Time - t_o_spill_5 ;
		                Spill_numberb = 5;
		                tree_spill->Fill();
		          	}

		         	 else if (Spill_number == 6  )
		         	 {
		               Time_spill_6= (Double_t) Time -t_begin[i];
		               duration_spill_6 = Time_spill_6 - Time_begin_spill_6;


		               Time_spill_6b = (Double_t) Time - t_o_spill_6;
		               Spill_numberb = 6;
		               tree_spill->Fill();
		         	 }

		        } // end of:  if (In_spill > 0.5 )
		 			}//end of: for (Long64_t jentry=0; jentry<nentries;jentry++)

					  	// ## 1

						  duration_spill =  duration_spill_1;
						  category = 1;
						  mi_cycle = 0;
							//myfile << mi_cycle << endl;
							//myfile4 << duration_spill << endl;
						  spill_global->Fill();

							// ## 2

							if(signal1_t_begin_spill_1 == 1 && signal1_t_begin_spill_2 == 1){

								  duration_spill =  duration_spill_2;
								  mi_cycle = t_o_spill_2 - t_o_spill_1;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

								  duration_spill =  duration_spill_2;
								  mi_cycle = 0;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							// ## 3

							if(signal1_t_begin_spill_3 == 1 && signal1_t_begin_spill_2 == 1){

								  duration_spill =  duration_spill_3;
								  mi_cycle = t_o_spill_3 - t_o_spill_2;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

								  duration_spill =  duration_spill_3;
								  mi_cycle = 0;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}

						  // ## 4
							if(signal1_t_begin_spill_3 == 1 && signal1_t_begin_spill_4 == 1){

								  duration_spill =  duration_spill_4;
								  mi_cycle =  t_o_spill_4 - t_o_spill_3;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

									duration_spill =  duration_spill_4;
								  mi_cycle = 0;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
						  // ## 5

							if(signal1_t_begin_spill_4 == 1 && signal1_t_begin_spill_5 == 1){

								  duration_spill =  duration_spill_5;
								  mi_cycle = t_o_spill_5 - t_o_spill_4;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

							}
							else {

							  duration_spill =  duration_spill_5;
							  mi_cycle = 0 ;
							  category = 1;
							  //myfile << mi_cycle << endl;
								//myfile4 << duration_spill << endl;
							  spill_global->Fill();

							}
						  // ## 6

							if(signal1_t_begin_spill_6 == 1 && signal1_t_begin_spill_5 == 1){

							  duration_spill =  duration_spill_6;
							  mi_cycle = t_o_spill_6 - t_o_spill_5;
							  category = 1;
							  //myfile << mi_cycle << endl;
								//myfile4 << duration_spill << endl;
							  spill_global->Fill();

							}
							else {

							  duration_spill =  duration_spill_6;
							  mi_cycle = 0;
							  category = 1;
							  //myfile << mi_cycle << endl;
								//myfile4 << duration_spill << endl;
							  spill_global->Fill();

							}


		}  // End For the ROOT files 10GeV Neg


		f_global.Write();
		f_spill.Write();

}


void TimeToolForRun::Plot1(){

      TTree *tree_spill;
      if (tree_spill == 0) {
         TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("spill_results_all_run2_pions.root");
         if (!f || !f->IsOpen()) {
            f = new TFile("spill_results_all_run2_pions.root");
         }
         f->GetObject("spill_global",spill_global);

      }


		  Double_t duration_spill, mi_cycle, temp ;
		  Int_t value_category ;
		  Int_t category ;
      Int_t energyb;
      Int_t polarityb;


      TBranch        *b_duration_spill;
      TBranch        *b_mi_cycle;
      TBranch        *b_category;
			TBranch        *b_energyb;
      TBranch        *b_polarityb;

			spill_global->SetMakeClass(1);
		  spill_global->SetBranchAddress("duration_spill", &duration_spill, &b_duration_spill);
		  spill_global->SetBranchAddress("mi_cycle", &mi_cycle, &b_mi_cycle);
		  spill_global->SetBranchAddress("category", &category, &b_category );
			spill_global->SetBranchAddress("energyb", &energyb, &b_energyb );
		  spill_global->SetBranchAddress("polarityb", &polarityb, &b_polarityb );

			// ==
			// Ploting Spill duration and MI Cycle

			TCanvas *c_spill_duration = new TCanvas("c_spill","Spill Duration",10,10,600,400);
			TText T; T.SetTextFont(42); T.SetTextAlign(21);
			c_spill_duration->Divide(1);
			c_spill_duration->cd(1);
			Int_t nbins2 = 100;
			Double_t xmin2 = 3.5;
			Double_t xmax2 = 4.2;

			TH1F *hist_spill_duration = new TH1F("hist_spill_duration","Spill Duration for Run 2",nbins2,xmin2,xmax2);
			TH1F *hist_spill_duration_1 = new TH1F("hist_spill_duration_1","Spill Duration for Run 2: 8GeV",nbins2,xmin2,xmax2);
			TH1F *hist_spill_duration_2 = new TH1F("hist_spill_duration_2","Spill Duration for Run 2: 6GeV",nbins2,xmin2,xmax2);
			TH1F *hist_spill_duration_3 = new TH1F("hist_spill_duration_3","Spill Duration for Run 2: 4GeV",nbins2,xmin2,xmax2);
			TH1F *hist_spill_duration_4 = new TH1F("hist_spill_duration_4","Spill Duration for Run 2: 9GeV",nbins2,xmin2,xmax2);
			TH1F *hist_spill_duration_5 = new TH1F("hist_spill_duration_5","Spill Duration for Run 2: 10GeV",nbins2,xmin2,xmax2);
			TH1F *hist_spill_duration_6 = new TH1F("hist_spill_duration_6","Spill Duration for Run 2: 16GeV",nbins2,xmin2,xmax2);

			spill_global->Project("hist_spill_duration","duration_spill", "duration_spill != 0");
			spill_global->Project("hist_spill_duration_1","duration_spill", "duration_spill != 0 && energyb == 8 ");
			spill_global->Project("hist_spill_duration_2","duration_spill", "duration_spill != 0 && energyb == 6");
			spill_global->Project("hist_spill_duration_3","duration_spill", "duration_spill != 0 && energyb == 4");
			spill_global->Project("hist_spill_duration_4","duration_spill", "duration_spill != 0 && energyb == 9");
			spill_global->Project("hist_spill_duration_5","duration_spill", "duration_spill != 0 && energyb == 10");
			spill_global->Project("hist_spill_duration_6","duration_spill", "duration_spill != 0 && energyb == 16");


				hist_spill_duration->GetXaxis()->SetTitle("Spill duration");
	      //hist_spill_duration->GetXaxis()->SetLimits(0, 5);
	      hist_spill_duration->SetTitle("Spill duration");
	      //hist_spill_duration->SetMarkerColor(2);
	      //hist_spill_duration->SetMarkerStyle(2);
	      gStyle->SetOptStat();
				hist_spill_duration->SetFillColor(kRed);
	      hist_spill_duration->Draw();
				c_spill_duration->Update();


	      //Int_t ci3, ci4, ci5, ci6, ci7, ci8, ci9, ci10, ci11;   // for color index setting
	      //ci2 = TColor::GetColor(2);
	      //hist_numb_spill_pions_2->SetLineColor(ci2);
	      hist_spill_duration_1->SetFillColor(kCyan);
	      hist_spill_duration_1->Draw("SAMES");

	      //hist_numb_spill_pions_4->SetFillColor(kViolet);
	      //hist_spill_number_date_3->SetLineColor(ci4);
	      //ci4 = TColor::GetColor(4);
	      hist_spill_duration_2->SetFillColor(kBlue);
	      hist_spill_duration_2->Draw("SAMES");

	      //hist_numb_spill_pions_5->SetFillColor(kBlue);
	      //hist_spill_number_date_4->SetLineColor(ci5);
	      //ci5 = TColor::GetColor(5);

	      hist_spill_duration_3->SetFillColor(kYellow);
	      hist_spill_duration_3->Draw("SAMES");

	      //hist_numb_spill_pions_6->SetFillColor(kAzure);
	      //hist_spill_number_date_5->SetLineColor(ci6);
	      //ci6 = TColor::GetColor(7);

	      hist_spill_duration_4->SetFillColor(kOrange);
	      hist_spill_duration_4->Draw("SAMES");

	      //hist_numb_spill_pions_7->SetFillColor(kCyan);
	      //hist_spill_number_date_6->SetLineColor(ci7);
	      //ci7 = TColor::GetColor(8);
				hist_spill_duration_5->SetFillColor(kGreen);
	      hist_spill_duration_5->Draw("SAMES");


				hist_spill_duration_6->SetFillColor(kViolet);
				hist_spill_duration_6->Draw("SAMES");



			 Double_t xl1=.18, yl1=0.40, xl2=xl1+.2, yl2=yl1+.325; // Set the X Axis title, value, etc
			 // x position, y position, x ancho, y ancho
			 TLegend *leg = new TLegend(xl1,yl1,xl2,yl2); // Legend
			 leg->SetHeader("For differents energies");
			 leg->AddEntry(hist_spill_duration,"All energies","f");
			 leg->AddEntry(hist_spill_duration_1,"8GeV","f");
			 leg->AddEntry(hist_spill_duration_2,"6GeV","f");
			 leg->AddEntry(hist_spill_duration_3,"4GeV","f");
			 leg->AddEntry(hist_spill_duration_4,"9GeV","f");
			 leg->AddEntry(hist_spill_duration_5,"10GeV","f");
			 leg->AddEntry(hist_spill_duration_6,"16GeV","f");
			 leg->Draw();


				TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
				ptstats->SetName("stats");
				ptstats->SetBorderSize(1);
				ptstats->SetFillColor(0);
				ptstats->SetTextAlign(12);
				ptstats->SetTextFont(42);
				TText *text = ptstats->AddText("Spill duration");
				text->SetTextSize(0.0068);
				char *entries_label = new char[12];
				Double_t entries_run =  spill_global->GetEntries();
				sprintf(entries_label," Entries %d", entries_run);
				text = ptstats->AddText(entries_label);
				char *mean_label = new char[12];
				Float_t mean_run =  hist_spill_duration->GetMean();
				sprintf(mean_label," Mean %0.2f", mean_run);
				text = ptstats->AddText(mean_label);
				char *rms_label = new char[12];
				Float_t rms_run =  hist_spill_duration->GetRMS();
				sprintf(rms_label," RMS %0.3f", rms_run);
				text = ptstats->AddText(rms_label);
				ptstats->SetOptStat(1111);
				ptstats->SetOptFit(0);
				ptstats->Draw();

				//T.DrawTextNDC(.5,.95,"Stacked Spill");


				c_spill_duration->SaveAs("spill_duration_all_run2_energies.gif");

}


void TimeToolForRun::Plot2(){

      TTree *tree_spill;
      if (tree_spill == 0) {
         TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("spill_results_all_run2_pions.root");
         if (!f || !f->IsOpen()) {
            f = new TFile("spill_results_all_run2_pions.root");
         }
         f->GetObject("spill_global",spill_global);

      }


		  Double_t duration_spill, mi_cycle, temp ;
		  Int_t value_category ;
		  Int_t category ;
      Int_t energyb;
      Int_t polarityb;


      TBranch        *b_duration_spill;
      TBranch        *b_mi_cycle;
      TBranch        *b_category;
			TBranch        *b_energyb;
      TBranch        *b_polarityb;

			spill_global->SetMakeClass(1);
		  spill_global->SetBranchAddress("duration_spill", &duration_spill, &b_duration_spill);
		  spill_global->SetBranchAddress("mi_cycle", &mi_cycle, &b_mi_cycle);
		  spill_global->SetBranchAddress("category", &category, &b_category );
			spill_global->SetBranchAddress("energyb", &energyb, &b_energyb );
		  spill_global->SetBranchAddress("polarityb", &polarityb, &b_polarityb );


		///////////////////////////////////

		TCanvas *c_spill_duration2 = new TCanvas("c_spill_duration2","Spill Duration",10,10,600,400);
		c_spill_duration2->Divide(1);
		c_spill_duration2->cd(1);
		Int_t nbins2 = 100;
		Double_t xmin2 = 3.5;
		Double_t xmax2 = 4.2;


			TH1F *hist_spill_duration = new TH1F("hist_spill_duration","Spill Duration for Run 2",nbins2,xmin2,xmax2);
			TH1F *hist_spill_duration_7 = new TH1F("hist_spill_duration_7","Spill Duration for Run 2 Pos",nbins2,xmin2,xmax2);
			TH1F *hist_spill_duration_8 = new TH1F("hist_spill_duration_8","Spill Duration for Run 2 Neg",nbins2,xmin2,xmax2);

			spill_global->Project("hist_spill_duration","duration_spill", "duration_spill != 0");
			spill_global->Project("hist_spill_duration_7","duration_spill", "duration_spill != 0 && polarityb == 1");
			spill_global->Project("hist_spill_duration_8","duration_spill", "duration_spill != 0 && polarityb == -1");


				hist_spill_duration->GetXaxis()->SetTitle("Spill duration");
	      //hist_spill_duration->GetXaxis()->SetLimits(0, 5);
	      hist_spill_duration->SetTitle("Spill duration");
	      //hist_spill_duration->SetMarkerColor(2);
	      //hist_spill_duration->SetMarkerStyle(2);
	      gStyle->SetOptStat();
				hist_spill_duration->SetFillColor(kRed);
	      hist_spill_duration->Draw();
				c_spill_duration2->Update();


	      //Int_t ci3, ci4, ci5, ci6, ci7, ci8, ci9, ci10, ci11;   // for color index setting
	      //ci2 = TColor::GetColor(2);
	      //hist_numb_spill_pions_2->SetLineColor(ci2);
	      hist_spill_duration_7->SetFillColor(kCyan);
	      hist_spill_duration_7->Draw("SAMES");

	      //hist_numb_spill_pions_4->SetFillColor(kViolet);
	      //hist_spill_number_date_3->SetLineColor(ci4);
	      //ci4 = TColor::GetColor(4);
	      hist_spill_duration_8->SetFillColor(kBlue);
	      hist_spill_duration_8->Draw("SAMES");


			 Double_t xl1=.18, yl1=0.40, xl2=xl1+.2, yl2=yl1+.325; // Set the X Axis title, value, etc
			 // x position, y position, x ancho, y ancho
			 TLegend *leg = new TLegend(xl1,yl1,xl2,yl2); // Legend
			 leg->SetHeader("For +/- pions ");
			 leg->AddEntry(hist_spill_duration,"All energies","f");
			 leg->AddEntry(hist_spill_duration_7,"Positive","f");
			 leg->AddEntry(hist_spill_duration_8,"Negative","f");
			 leg->Draw();


				TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
				ptstats->SetName("stats");
				ptstats->SetBorderSize(1);
				ptstats->SetFillColor(0);
				ptstats->SetTextAlign(12);
				ptstats->SetTextFont(42);
				TText *text = ptstats->AddText("Spill duration");
				text->SetTextSize(0.0068);
				char *entries_label = new char[12];
				Double_t entries_run =  spill_global->GetEntries();
				sprintf(entries_label," Entries %d", entries_run);
				text = ptstats->AddText(entries_label);
				char *mean_label = new char[12];
				Float_t mean_run =  hist_spill_duration->GetMean();
				sprintf(mean_label," Mean %0.2f", mean_run);
				text = ptstats->AddText(mean_label);
				char *rms_label = new char[12];
				Float_t rms_run =  hist_spill_duration->GetRMS();
				sprintf(rms_label," RMS %0.3f", rms_run);
				text = ptstats->AddText(rms_label);
				ptstats->SetOptStat(1111);
				ptstats->SetOptFit(0);
				ptstats->Draw();

				//T.DrawTextNDC(.5,.95,"Stacked Spill");



				c_spill_duration2->SaveAs("spill_duration_all_run2_polarities.gif");

	}



	void TimeToolForRun::Plot3(){

	      TTree *tree_spill;
	      if (tree_spill == 0) {
	         TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("spill_results_all_run2_pions.root");
	         if (!f || !f->IsOpen()) {
	            f = new TFile("spill_results_all_run2_pions.root");
	         }
	         f->GetObject("spill_global",spill_global);

	      }


			  Double_t duration_spill, mi_cycle, temp ;
			  Int_t value_category ;
			  Int_t category ;
	      Int_t energyb;
	      Int_t polarityb;


	      TBranch        *b_duration_spill;
	      TBranch        *b_mi_cycle;
	      TBranch        *b_category;
				TBranch        *b_energyb;
	      TBranch        *b_polarityb;

				spill_global->SetMakeClass(1);
			  spill_global->SetBranchAddress("duration_spill", &duration_spill, &b_duration_spill);
			  spill_global->SetBranchAddress("mi_cycle", &mi_cycle, &b_mi_cycle);
			  spill_global->SetBranchAddress("category", &category, &b_category );
				spill_global->SetBranchAddress("energyb", &energyb, &b_energyb );
			  spill_global->SetBranchAddress("polarityb", &polarityb, &b_polarityb );


				TCanvas *c_mi_cycle = new TCanvas("c_mi_cycle","MI CYCLE",10,10,600,400);
				c_mi_cycle->Divide(1);
				c_mi_cycle->cd(1);

				Int_t nbins3 = 250;
				Double_t xmin3 = 60;
				Double_t xmax3 = 61;

				TH1F *hist_mi_cycle = new TH1F("hist_mi_cycle","MI Cycle for All energies and Polarities Pions ",nbins3,xmin3,xmax3);
				spill_global->Project("hist_mi_cycle","mi_cycle","mi_cycle != 0");
				hist_mi_cycle->Draw();
				hist_mi_cycle->GetXaxis()->SetTitle("Time (seconds)");
				hist_mi_cycle->Draw();
				c_mi_cycle->SaveAs("mi_cycle_all_run.gif");


					TH1F *hist_mi_cycle = new TH1F("hist_mi_cycle","MI Cycle for All energies and Polarities Pions ",nbins3,xmin3,xmax3);
					TH1F *hist_mi_cycle_1= new TH1F("hist_mi_cycle_1","MI Cycle for 8Gev",nbins3,xmin3,xmax3);
					TH1F *hist_mi_cycle_2 = new TH1F("hist_mi_cycle_2","MI Cycle for 6Gev",nbins3,xmin3,xmax3);
					TH1F *hist_mi_cycle_3 = new TH1F("hist_mi_cycle_3","MI Cycle for 4Gev",nbins3,xmin3,xmax3);
					TH1F *hist_mi_cycle_4 = new TH1F("hist_mi_cycle_4","MI Cycle for 9Gev",nbins3,xmin3,xmax3);
					TH1F *hist_mi_cycle_5 = new TH1F("hist_mi_cycle_5","MI Cycle for 10Gev",nbins3,xmin3,xmax3);
					TH1F *hist_mi_cycle_6 = new TH1F("hist_mi_cycle_6","MI Cycle for 16Gev",nbins3,xmin3,xmax3);

					spill_global->Project("hist_mi_cycle","mi_cycle","mi_cycle != 0");
					spill_global->Project("hist_mi_cycle_1","mi_cycle","mi_cycle != 0 && energyb == 8 ");
					spill_global->Project("hist_mi_cycle_2","mi_cycle","mi_cycle != 0 && energyb == 6 ");
					spill_global->Project("hist_mi_cycle_3","mi_cycle","mi_cycle != 0 && energyb == 4 ");
					spill_global->Project("hist_mi_cycle_4","mi_cycle","mi_cycle != 0 && energyb == 9 ");
					spill_global->Project("hist_mi_cycle_5","mi_cycle","mi_cycle != 0 && energyb == 10 ");
					spill_global->Project("hist_mi_cycle_6","mi_cycle","mi_cycle != 0 && energyb == 16 ");

					hist_mi_cycle->GetXaxis()->SetTitle("MI Cycle");
				  //hist_mi_cycle->GetXaxis()->SetLimits(0, 5);
				  hist_mi_cycle->SetTitle("MI Cycle for Run 2 Pions");
				  //hist_mi_cycle->SetMarkerColor(2);
				  //hist_mi_cycle->SetMarkerStyle(2);
				  gStyle->SetOptStat();
				  hist_mi_cycle->SetFillColor(kRed);
				  hist_mi_cycle->Draw();
				  c_mi_cycle->Update();


				  //Int_t ci3, ci4, ci5, ci6, ci7, ci8, ci9, ci10, ci11;   // for color index setting
				  //ci2 = TColor::GetColor(2);
				  //hist_numb_spill_pions_2->SetLineColor(ci2);
				  hist_mi_cycle_1->SetFillColor(kCyan);
				  hist_mi_cycle_1->Draw("SAMES");

				  //hist_numb_spill_pions_4->SetFillColor(kViolet);
				  //hist_spill_number_date_3->SetLineColor(ci4);
				  //ci4 = TColor::GetColor(4);
				  hist_mi_cycle_2->SetFillColor(kBlue);
				  hist_mi_cycle_2->Draw("SAMES");

				  //hist_numb_spill_pions_5->SetFillColor(kBlue);
				  //hist_spill_number_date_4->SetLineColor(ci5);
				  //ci5 = TColor::GetColor(5);

				  hist_mi_cycle_3->SetFillColor(kYellow);
				  hist_mi_cycle_3->Draw("SAMES");

				  //hist_numb_spill_pions_6->SetFillColor(kAzure);
				  //hist_spill_number_date_5->SetLineColor(ci6);
				  //ci6 = TColor::GetColor(7);

				  hist_mi_cycle_4->SetFillColor(kOrange);
				  hist_mi_cycle_4->Draw("SAMES");

				  //hist_numb_spill_pions_7->SetFillColor(kCyan);
				  //hist_spill_number_date_6->SetLineColor(ci7);
				  //ci7 = TColor::GetColor(8);
				  hist_mi_cycle_5->SetFillColor(kGreen);
				  hist_mi_cycle_5->Draw("SAMES");


				  hist_mi_cycle_6->SetFillColor(kViolet);
				  hist_mi_cycle_6->Draw("SAMES");



				 Double_t xl1=.18, yl1=0.40, xl2=xl1+.2, yl2=yl1+.325; // Set the X Axis title, value, etc
				 // x position, y position, x ancho, y ancho
				 TLegend *leg = new TLegend(xl1,yl1,xl2,yl2); // Legend
				 leg->SetHeader("For differents energies");
				 leg->AddEntry(hist_mi_cycle,"All energies","f");
				 leg->AddEntry(hist_mi_cycle_1,"8GeV","f");
				 leg->AddEntry(hist_mi_cycle_2,"6GeV","f");
				 leg->AddEntry(hist_mi_cycle_3,"4GeV","f");
				 leg->AddEntry(hist_mi_cycle_4,"9GeV","f");
				 leg->AddEntry(hist_mi_cycle_5,"10GeV","f");
				 leg->AddEntry(hist_mi_cycle_6,"16GeV","f");
				 leg->Draw();


						TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
						ptstats->SetName("stats");
						ptstats->SetBorderSize(1);
						ptstats->SetFillColor(0);
						ptstats->SetTextAlign(12);
						ptstats->SetTextFont(42);
						TText *text = ptstats->AddText("MI Cycle");
						text->SetTextSize(0.0068);
						char *entries_label = new char[12];
						Double_t entries_run =  hist_mi_cycle->GetEntries();
						sprintf(entries_label," Entries %d", entries_run);
						text = ptstats->AddText(entries_label);
						char *mean_label = new char[12];
						Float_t mean_run =  hist_mi_cycle->GetMean();
						sprintf(mean_label," Mean %0.2f", mean_run);
						text = ptstats->AddText(mean_label);
						char *rms_label = new char[12];
						Float_t rms_run =  hist_mi_cycle->GetRMS();
						sprintf(rms_label," RMS %0.3f", rms_run);
						text = ptstats->AddText(rms_label);
						ptstats->SetOptStat(1111);
						ptstats->SetOptFit(0);
						ptstats->Draw();

						//T.DrawTextNDC(.5,.95,"Stacked Spill");


						c_mi_cycle->SaveAs("mi_cycle_all_run2_energies.gif");

	}



	void TimeToolForRun::Plot4(){

	      TTree *tree_spill;
	      if (tree_spill == 0) {
	         TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("spill_results_all_run2_pions.root");
	         if (!f || !f->IsOpen()) {
	            f = new TFile("spill_results_all_run2_pions.root");
	         }
	         f->GetObject("spill_global",spill_global);

	      }


			  Double_t duration_spill, mi_cycle, temp ;
			  Int_t value_category ;
			  Int_t category ;
	      Int_t energyb;
	      Int_t polarityb;


	      TBranch        *b_duration_spill;
	      TBranch        *b_mi_cycle;
	      TBranch        *b_category;
				TBranch        *b_energyb;
	      TBranch        *b_polarityb;

				spill_global->SetMakeClass(1);
			  spill_global->SetBranchAddress("duration_spill", &duration_spill, &b_duration_spill);
			  spill_global->SetBranchAddress("mi_cycle", &mi_cycle, &b_mi_cycle);
			  spill_global->SetBranchAddress("category", &category, &b_category );
				spill_global->SetBranchAddress("energyb", &energyb, &b_energyb );
			  spill_global->SetBranchAddress("polarityb", &polarityb, &b_polarityb );


				TCanvas *c_mi_cycle = new TCanvas("c_mi_cycle","MI CYCLE",10,10,600,400);
				c_mi_cycle->Divide(1);
				c_mi_cycle->cd(1);

				Int_t nbins3 = 250;
				Double_t xmin3 = 60;
				Double_t xmax3 = 61;


				TH1F *hist_mi_cycle = new TH1F("hist_mi_cycle","MI Cycle for All energies and Polarities Pions ",nbins3,xmin3,xmax3);
				TH1F *hist_mi_cycle_1= new TH1F("hist_mi_cycle_1","MI Cycle for Pos Pions",nbins3,xmin3,xmax3);
				TH1F *hist_mi_cycle_2 = new TH1F("hist_mi_cycle_2","MI Cycle for Neg Pions",nbins3,xmin3,xmax3);

				spill_global->Project("hist_mi_cycle","mi_cycle","mi_cycle != 0");
				spill_global->Project("hist_mi_cycle_1","mi_cycle","mi_cycle != 0 && polarityb == 1 ");
				spill_global->Project("hist_mi_cycle_2","mi_cycle","mi_cycle != 0 && polarityb == -1 ");

				hist_mi_cycle->GetXaxis()->SetTitle("MI Cycle");
				//hist_mi_cycle->GetXaxis()->SetLimits(0, 5);
				hist_mi_cycle->SetTitle("MI Cycle for Pos and Neg Pions");
				//hist_mi_cycle->SetMarkerColor(2);
				//hist_mi_cycle->SetMarkerStyle(2);
				gStyle->SetOptStat();
				hist_mi_cycle->SetFillColor(kRed);
				hist_mi_cycle->Draw();
				c_mi_cycle->Update();


				hist_mi_cycle_1->SetFillColor(kCyan);
				hist_mi_cycle_1->Draw("SAMES");
				hist_mi_cycle_2->SetFillColor(kBlue);
				hist_mi_cycle_2->Draw("SAMES");

				Double_t xl1=.18, yl1=0.40, xl2=xl1+.2, yl2=yl1+.325; // Set the X Axis title, value, etc
				TLegend *leg = new TLegend(xl1,yl1,xl2,yl2); // Legend
				leg->SetHeader("For differents energies");
				leg->AddEntry(hist_mi_cycle,"All energies","f");
				leg->AddEntry(hist_mi_cycle_1,"Pos Pions","f");
				leg->AddEntry(hist_mi_cycle_2,"Neg Pions","f");
				leg->Draw();


				TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
				ptstats->SetName("stats");
				ptstats->SetBorderSize(1);
				ptstats->SetFillColor(0);
				ptstats->SetTextAlign(12);
				ptstats->SetTextFont(42);
				TText *text = ptstats->AddText("MI Cycle");
				text->SetTextSize(0.0068);
				char *entries_label = new char[12];
				Double_t entries_run =  hist_mi_cycle->GetEntries();
				sprintf(entries_label," Entries %d", entries_run);
				text = ptstats->AddText(entries_label);
				char *mean_label = new char[12];
				Float_t mean_run =  hist_mi_cycle->GetMean();
				sprintf(mean_label," Mean %0.2f", mean_run);
				text = ptstats->AddText(mean_label);
				char *rms_label = new char[12];
				Float_t rms_run =  hist_mi_cycle->GetRMS();
				sprintf(rms_label," RMS %0.3f", rms_run);
				text = ptstats->AddText(rms_label);
				ptstats->SetOptStat(1111);
				ptstats->SetOptFit(0);
				ptstats->Draw();

				c_mi_cycle->SaveAs("mi_cycle_all_run2_polarities.gif");

	}
