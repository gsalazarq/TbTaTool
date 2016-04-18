#define TimeToolForRun_cxx
#include "TimeToolForRun.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "Riostream.h"
#include <fstream>

void TimeToolForRun(){


    const char* name_file[1000] = {

			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001717_0001_cosmc_v09_1506271603_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001717_0002_cosmc_v09_1506271614_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001717_0003_cosmc_v09_1506271629_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001717_0004_cosmc_v09_1506271640_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001717_0005_cosmc_v09_1506271651_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001717_0006_cosmc_v09_1506271702_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001717_0007_cosmc_v09_1506271713_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001717_0008_cosmc_v09_1506271724_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001717_0009_cosmc_v09_1506271735_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001717_0010_cosmc_v09_1506271747_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001717_0011_cosmc_v09_1506271758_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001717_0012_cosmc_v09_1506271809_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001717_0013_cosmc_v09_1506271820_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001717_0014_cosmc_v09_1506271831_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001717_0015_cosmc_v09_1506271842_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001717_0016_cosmc_v09_1506271853_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001717_0017_cosmc_v09_1506271904_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001717_0018_cosmc_v09_1506271916_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001717_0019_cosmc_v09_1506271926_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001717_0020_cosmc_v09_1506271937_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001717_0021_cosmc_v09_1506271949_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001717_0022_cosmc_v09_1506272003_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001717_0023_cosmc_v09_1506272015_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001717_0024_cosmc_v09_1506272026_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001717_0025_cosmc_v09_1506272037_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001718_0001_cosmc_v09_1506272048_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001718_0002_cosmc_v09_1506272059_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001718_0003_cosmc_v09_1506272111_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001718_0004_cosmc_v09_1506272122_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001718_0005_cosmc_v09_1506272133_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001721_0001_cosmc_v09_1506272153_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001721_0002_cosmc_v09_1506272205_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001721_0003_cosmc_v09_1506272216_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001721_0004_cosmc_v09_1506272227_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001721_0005_cosmc_v09_1506272238_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001721_0006_cosmc_v09_1506272249_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001721_0007_cosmc_v09_1506272300_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001721_0008_cosmc_v09_1506272311_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001721_0009_cosmc_v09_1506272322_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001721_0010_cosmc_v09_1506272334_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001721_0011_cosmc_v09_1506272348_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001721_0012_cosmc_v09_1506272359_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001721_0013_cosmc_v09_1506280010_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001721_0014_cosmc_v09_1506280021_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001721_0015_cosmc_v09_1506280033_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001721_0016_cosmc_v09_1506280045_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001721_0017_cosmc_v09_1506280056_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001721_0018_cosmc_v09_1506280108_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001721_0019_cosmc_v09_1506280119_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001721_0020_cosmc_v09_1506280131_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Pos_Electrons/TB_00001721_0021_cosmc_v09_1506280142_camac.root",


			// 4GeV Pos

			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001723_0001_cosmc_v09_1506280220_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001723_0002_cosmc_v09_1506280232_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001723_0003_cosmc_v09_1506280242_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001723_0004_cosmc_v09_1506280252_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001723_0005_cosmc_v09_1506280302_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001723_0006_cosmc_v09_1506280312_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001723_0007_cosmc_v09_1506280322_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001723_0008_cosmc_v09_1506280332_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001723_0009_cosmc_v09_1506280342_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001723_0010_cosmc_v09_1506280353_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001723_0011_cosmc_v09_1506280403_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001723_0012_cosmc_v09_1506280414_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001723_0013_cosmc_v09_1506280424_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001723_0014_cosmc_v09_1506280434_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001723_0015_cosmc_v09_1506280444_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001723_0016_cosmc_v09_1506280454_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001723_0017_cosmc_v09_1506280507_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001723_0018_cosmc_v09_1506280517_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001723_0019_cosmc_v09_1506280528_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001723_0020_cosmc_v09_1506280539_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001723_0021_cosmc_v09_1506280549_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001723_0022_cosmc_v09_1506280559_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001723_0023_cosmc_v09_1506280609_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001723_0024_cosmc_v09_1506280620_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001723_0025_cosmc_v09_1506280631_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001724_0001_cosmc_v09_1506280647_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001724_0002_cosmc_v09_1506280658_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001724_0003_cosmc_v09_1506280708_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001724_0004_cosmc_v09_1506280718_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001724_0005_cosmc_v09_1506280728_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001724_0006_cosmc_v09_1506280738_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001724_0007_cosmc_v09_1506280748_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001724_0008_cosmc_v09_1506280758_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001724_0009_cosmc_v09_1506280808_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001724_0010_cosmc_v09_1506280825_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001724_0011_cosmc_v09_1506280837_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001724_0012_cosmc_v09_1506280847_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001724_0013_cosmc_v09_1506280857_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001724_0014_cosmc_v09_1506280907_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001724_0015_cosmc_v09_1506280918_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001724_0016_cosmc_v09_1506280928_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001724_0017_cosmc_v09_1506280938_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001724_0018_cosmc_v09_1506280948_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001724_0019_cosmc_v09_1506280958_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001724_0020_cosmc_v09_1506281008_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001724_0021_cosmc_v09_1506281018_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001724_0022_cosmc_v09_1506281028_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001724_0023_cosmc_v09_1506281038_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001724_0024_cosmc_v09_1506281048_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Pos_Electrons/TB_00001724_0025_cosmc_v09_1506281059_camac.root",

			// 8 Pos

			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Pos_Electrons/TB_00001728_0001_cosmc_v09_1506281148_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Pos_Electrons/TB_00001728_0002_cosmc_v09_1506281200_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Pos_Electrons/TB_00001728_0003_cosmc_v09_1506281210_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Pos_Electrons/TB_00001728_0004_cosmc_v09_1506281220_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Pos_Electrons/TB_00001728_0005_cosmc_v09_1506281230_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Pos_Electrons/TB_00001769_0001_cosmc_v09_1507030536_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Pos_Electrons/TB_00001769_0002_cosmc_v09_1507030549_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Pos_Electrons/TB_00001769_0003_cosmc_v09_1507030600_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Pos_Electrons/TB_00001769_0004_cosmc_v09_1507030610_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Pos_Electrons/TB_00001769_0005_cosmc_v09_1507030620_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Pos_Electrons/TB_00001769_0006_cosmc_v09_1507030630_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Pos_Electrons/TB_00001769_0007_cosmc_v09_1507030640_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Pos_Electrons/TB_00001769_0008_cosmc_v09_1507030650_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Pos_Electrons/TB_00001769_0009_cosmc_v09_1507030700_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Pos_Electrons/TB_00001769_0010_cosmc_v09_1507030711_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Pos_Electrons/TB_00001769_0011_cosmc_v09_1507030721_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Pos_Electrons/TB_00001769_0012_cosmc_v09_1507030731_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Pos_Electrons/TB_00001769_0013_cosmc_v09_1507030741_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Pos_Electrons/TB_00001769_0014_cosmc_v09_1507030751_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Pos_Electrons/TB_00001769_0015_cosmc_v09_1507030801_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Pos_Electrons/TB_00001769_0016_cosmc_v09_1507030811_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Pos_Electrons/TB_00001769_0017_cosmc_v09_1507030821_camac.root",
			//"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Pos_Electrons/TB_00001769_0018_cosmc_v09_1507030831_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001760_0001_cosmc_v09_1507020353_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001760_0002_cosmc_v09_1507020404_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001760_0003_cosmc_v09_1507020415_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001760_0004_cosmc_v09_1507020426_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001760_0005_cosmc_v09_1507020437_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0001_cosmc_v09_1507021350_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0002_cosmc_v09_1507021354_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0003_cosmc_v09_1507021406_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0004_cosmc_v09_1507021416_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0005_cosmc_v09_1507021427_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0006_cosmc_v09_1507021437_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0007_cosmc_v09_1507021457_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0008_cosmc_v09_1507021508_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0009_cosmc_v09_1507021519_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0010_cosmc_v09_1507021555_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0011_cosmc_v09_1507021608_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0012_cosmc_v09_1507021619_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0013_cosmc_v09_1507021631_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0014_cosmc_v09_1507021732_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0015_cosmc_v09_1507021743_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0016_cosmc_v09_1507021753_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0017_cosmc_v09_1507021804_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0018_cosmc_v09_1507021814_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0019_cosmc_v09_1507021824_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0020_cosmc_v09_1507021834_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0021_cosmc_v09_1507021844_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0022_cosmc_v09_1507021854_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0023_cosmc_v09_1507021904_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0024_cosmc_v09_1507021916_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0025_cosmc_v09_1507021927_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0026_cosmc_v09_1507021938_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0027_cosmc_v09_1507021948_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0028_cosmc_v09_1507022001_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0029_cosmc_v09_1507022012_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0030_cosmc_v09_1507022023_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0031_cosmc_v09_1507022033_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0032_cosmc_v09_1507022044_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0033_cosmc_v09_1507022055_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0034_cosmc_v09_1507022105_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0035_cosmc_v09_1507022116_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0036_cosmc_v09_1507022129_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0037_cosmc_v09_1507022139_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/8GeV_Neg_Electrons/TB_00001765_0038_cosmc_v09_1507022149_camac.root",

			// 3 Pos

			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/3GeV_Pos_Electrons/TB_00001771_0001_cosmc_v09_1507031038_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/3GeV_Pos_Electrons/TB_00001771_0002_cosmc_v09_1507031049_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/3GeV_Pos_Electrons/TB_00001771_0003_cosmc_v09_1507031100_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/3GeV_Pos_Electrons/TB_00001771_0004_cosmc_v09_1507031111_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/3GeV_Pos_Electrons/TB_00001771_0005_cosmc_v09_1507031121_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/3GeV_Pos_Electrons/TB_00001771_0006_cosmc_v09_1507031131_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/3GeV_Pos_Electrons/TB_00001771_0007_cosmc_v09_1507031135_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/3GeV_Pos_Electrons/TB_00001771_0008_cosmc_v09_1507031145_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/3GeV_Pos_Electrons/TB_00001771_0009_cosmc_v09_1507031155_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/3GeV_Pos_Electrons/TB_00001771_0010_cosmc_v09_1507031205_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/3GeV_Pos_Electrons/TB_00001771_0011_cosmc_v09_1507031216_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/3GeV_Pos_Electrons/TB_00001771_0012_cosmc_v09_1507031229_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/3GeV_Pos_Electrons/TB_00001771_0013_cosmc_v09_1507031239_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/3GeV_Pos_Electrons/TB_00001771_0014_cosmc_v09_1507031252_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/3GeV_Pos_Electrons/TB_00001771_0015_cosmc_v09_1507031303_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/3GeV_Pos_Electrons/TB_00001771_0016_cosmc_v09_1507031313_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/3GeV_Pos_Electrons/TB_00001771_0017_cosmc_v09_1507031323_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/3GeV_Pos_Electrons/TB_00001771_0018_cosmc_v09_1507031333_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/3GeV_Pos_Electrons/TB_00001771_0019_cosmc_v09_1507031344_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/3GeV_Pos_Electrons/TB_00001771_0020_cosmc_v09_1507031355_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/3GeV_Pos_Electrons/TB_00001771_0021_cosmc_v09_1507031406_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/3GeV_Pos_Electrons/TB_00001771_0022_cosmc_v09_1507031417_camac.root",

			// 5 +

			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/5GeV_Pos_Electrons/TB_00001772_0001_cosmc_v09_1507031448_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/5GeV_Pos_Electrons/TB_00001772_0002_cosmc_v09_1507031459_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/5GeV_Pos_Electrons/TB_00001772_0003_cosmc_v09_1507031509_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/5GeV_Pos_Electrons/TB_00001772_0004_cosmc_v09_1507031519_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/5GeV_Pos_Electrons/TB_00001772_0005_cosmc_v09_1507031529_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/5GeV_Pos_Electrons/TB_00001772_0006_cosmc_v09_1507031539_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/5GeV_Pos_Electrons/TB_00001772_0007_cosmc_v09_1507031549_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/5GeV_Pos_Electrons/TB_00001772_0008_cosmc_v09_1507031620_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/5GeV_Pos_Electrons/TB_00001772_0009_cosmc_v09_1507031632_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/5GeV_Pos_Electrons/TB_00001772_0010_cosmc_v09_1507031709_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/5GeV_Pos_Electrons/TB_00001772_0011_cosmc_v09_1507031719_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/5GeV_Pos_Electrons/TB_00001772_0012_cosmc_v09_1507031729_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/5GeV_Pos_Electrons/TB_00001772_0013_cosmc_v09_1507031739_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/5GeV_Pos_Electrons/TB_00001772_0014_cosmc_v09_1507031749_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/5GeV_Pos_Electrons/TB_00001772_0015_cosmc_v09_1507031759_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/5GeV_Pos_Electrons/TB_00001772_0016_cosmc_v09_1507031809_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/5GeV_Pos_Electrons/TB_00001772_0017_cosmc_v09_1507031819_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/5GeV_Pos_Electrons/TB_00001772_0018_cosmc_v09_1507031829_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/5GeV_Pos_Electrons/TB_00001772_0019_cosmc_v09_1507031849_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/5GeV_Pos_Electrons/TB_00001772_0020_cosmc_v09_1507031900_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/5GeV_Pos_Electrons/TB_00001772_0021_cosmc_v09_1507031911_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/5GeV_Pos_Electrons/TB_00001772_0022_cosmc_v09_1507031922_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/5GeV_Pos_Electrons/TB_00001772_0023_cosmc_v09_1507031932_camac.root",

			// 2 -

			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Neg_Electrons/TB_00001773_0001_cosmc_v09_1507031956_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Neg_Electrons/TB_00001773_0002_cosmc_v09_1507032008_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Neg_Electrons/TB_00001773_0003_cosmc_v09_1507032019_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Neg_Electrons/TB_00001773_0004_cosmc_v09_1507032030_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Neg_Electrons/TB_00001773_0005_cosmc_v09_1507032042_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Neg_Electrons/TB_00001773_0006_cosmc_v09_1507032053_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Neg_Electrons/TB_00001773_0007_cosmc_v09_1507032104_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Neg_Electrons/TB_00001773_0008_cosmc_v09_1507032115_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Neg_Electrons/TB_00001773_0009_cosmc_v09_1507032126_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Neg_Electrons/TB_00001773_0010_cosmc_v09_1507032137_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Neg_Electrons/TB_00001773_0011_cosmc_v09_1507032149_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Neg_Electrons/TB_00001773_0012_cosmc_v09_1507032200_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Neg_Electrons/TB_00001773_0013_cosmc_v09_1507032213_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Neg_Electrons/TB_00001773_0014_cosmc_v09_1507032224_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Neg_Electrons/TB_00001773_0015_cosmc_v09_1507032235_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Neg_Electrons/TB_00001773_0016_cosmc_v09_1507032247_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Neg_Electrons/TB_00001773_0017_cosmc_v09_1507032258_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Neg_Electrons/TB_00001773_0018_cosmc_v09_1507032309_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Neg_Electrons/TB_00001773_0019_cosmc_v09_1507032320_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Neg_Electrons/TB_00001773_0020_cosmc_v09_1507032331_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Neg_Electrons/TB_00001773_0021_cosmc_v09_1507032342_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Neg_Electrons/TB_00001773_0022_cosmc_v09_1507032354_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Neg_Electrons/TB_00001773_0023_cosmc_v09_1507040006_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Neg_Electrons/TB_00001773_0024_cosmc_v09_1507040018_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/2GeV_Neg_Electrons/TB_00001773_0025_cosmc_v09_1507040029_camac.root",

			//4 -

			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Neg_Electrons/TB_00001774_0001_cosmc_v09_1507040053_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Neg_Electrons/TB_00001774_0002_cosmc_v09_1507040105_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Neg_Electrons/TB_00001774_0003_cosmc_v09_1507040115_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Neg_Electrons/TB_00001774_0004_cosmc_v09_1507040125_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Neg_Electrons/TB_00001774_0005_cosmc_v09_1507040135_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Neg_Electrons/TB_00001774_0006_cosmc_v09_1507040145_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Neg_Electrons/TB_00001774_0007_cosmc_v09_1507040156_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Neg_Electrons/TB_00001774_0008_cosmc_v09_1507040233_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Neg_Electrons/TB_00001774_0009_cosmc_v09_1507040245_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Neg_Electrons/TB_00001774_0010_cosmc_v09_1507040256_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Neg_Electrons/TB_00001774_0011_cosmc_v09_1507040308_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Neg_Electrons/TB_00001774_0012_cosmc_v09_1507040319_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Neg_Electrons/TB_00001774_0013_cosmc_v09_1507040329_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Neg_Electrons/TB_00001774_0014_cosmc_v09_1507040422_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Neg_Electrons/TB_00001774_0015_cosmc_v09_1507040439_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Neg_Electrons/TB_00001774_0016_cosmc_v09_1507040449_camac.root",
			"/home/gsalazarq/sources/root/root/bin/files/run3_electron/4GeV_Neg_Electrons/TB_00001774_0017_cosmc_v09_1507040500_camac.root",

				};


    TFile *f[1000];
    TTree *tree[1000];

    Long64_t nentries_1, nentries_2, nentries_3, nentries_4, nentries_5, nentries_6;
    Long64_t sum1, sum2, sum3, sum4;
    nentries_1 = -404; nentries_2 = -404; nentries_3 = -404;
    sum1 = 0;  sum2 = 0; sum3 = 0 ; sum4 = 0;

    TString variable2 = "/home/gsalazarq/Dropbox/min_conocimiento/e45.MINERvA/tools/final_tools/final_final_tools/number_spills_entries/values_all.txt";
    char * myfile_name = variable2 ;
    ofstream myfile2 (myfile_name, ios::out | ios::app);
    if (myfile2.is_open());
    myfile2 <<"###" << endl;


    for(Int_t i=0; i<51+50+23+22+23+25+17; i++){ //For() over all the root files
        cout <<  i  << "." << endl  ;

        // Open the array_root_file[i] and the corresponding tree[i]

        f[i] = (TFile*)gROOT->GetListOfFiles()->FindObject(name_file[i]);

          if (!f[i] || !f[i]->IsOpen()) {
             f[i] = new TFile(name_file[i],"READ");
          }


        f[i]->GetObject("CAMACTree",tree[i]);
        //Init(tree[i]) ;
        //TimeToolForRun::Init(tree[i]);
      //  Init(tree[i]);      //f[i] equal to the tree corresponding to the array_file_root[i]

        // Tbegin of for each number of spills

        nentries_1 = tree[i]->GetEntries("In_spill > 0.5");
        nentries_2 = tree[i]->GetEntries("In_spill > 0.5 && Spill_number < 7");
        nentries_3 = tree[i]->GetEntries("In_spill > 0.5 && Spill_number < 3");
        nentries_4 = tree[i]->GetEntries("In_spill > 0.5 && Spill_number < 11");

        sum1 = nentries_1 + sum1;
        sum2 = nentries_2 + sum2;
        sum3 = nentries_3 + sum3;
        sum4 = nentries_4 + sum4;


      }


        myfile2 << "Spill number All: " << sum1 << endl;
        myfile2 << "Spill number 11: " << sum4 << endl;
        myfile2 << "Spill number 6: " << sum2 << endl;
        myfile2 << "Spill number 2: " << sum3 << endl;
        myfile2 <<"###" << endl;



}



void TimeToolForRun::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Time", &Time, &b_Time);
   fChain->SetBranchAddress("Spill_number", &Spill_number, &b_Spill_number);
   fChain->SetBranchAddress("Triggers_in_spill", &Triggers_in_spill, &b_Triggers_in_spill);
   fChain->SetBranchAddress("Triggers_out_spill", &Triggers_out_spill, &b_Triggers_out_spill);
   fChain->SetBranchAddress("In_spill", &In_spill, &b_In_spill);
   Notify();
}
