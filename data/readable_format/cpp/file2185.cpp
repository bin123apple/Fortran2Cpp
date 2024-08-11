#include <vector>
#include <string>
#include <array>

struct MOD_Analyze_Vars {
    int nWriteData = 1;
    float analyze_dt;
    float WriteData_dt;
    float tWriteData;

#if FV_ENABLED
    int totalFV_nElems = 0;
#endif

#if PP_LIMITER
    int totalPP_nElems = 0;
#endif

    std::vector<std::vector<float>> wGPSurf;
    std::vector<std::vector<std::vector<float>>> wGPVol;
    std::vector<float> Surf;
    std::vector<float> ElemVol;
    float Vol;
    bool doCalcErrorNorms = false;
    bool doAnalyzeToFile = false;
    float iterRestart = 0;
    float calcTimeRestart = 0.0;
    int NAnalyze;
    int NAnalyzeZ;
    int AnalyzeExactFunc;
    int AnalyzeRefState;
    std::vector<std::vector<std::vector<float>>> wGPVolAnalyze;
    std::vector<std::vector<float>> Vdm_GaussN_NAnalyze;
    std::string Filename_ErrNorm;
    bool AnalyzeInitIsDone = false;
};

int main() {
    MOD_Analyze_Vars analyzeVars;
    // Initialization and usage of analyzeVars goes here.
    return 0;
}