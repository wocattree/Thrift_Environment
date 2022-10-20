////////////////////////////////
//filename:SimuTempModule.h
//description:模拟温度产生模块
//data:2022/09/17 20:12:01
//author:wocattree
////////////////////////////////

#pragma once
#include "ModuleBase.h"

namespace SimuData
{
    namespace TempInfo
    {
        class CModuleSimuTemp : public CModuleBase
        {
        public:
            CModuleSimuTemp(CDevice *pDevice);
            ~CModuleSimuTemp();

            ////////////////////////////////
            //funcname:GetSimuTemoInfos
            //description:返回随机温度值数组
            //param:
            //return:
            //data:2022/09/17 21:29:38
            //author:wocattree
            ///////////////////////////////
            std::vector<float> GetSimuTemoInfos();

        /*    int Run();*/

        private:
            std::vector<float>                vSimuTempInfos;            //模拟产生的温度数值列表
            int                               TempIndex;                         //温度值数组索引
        
        private:
            ////////////////////////////////
            //funcname:ProduceTemps
            //description:产生随机温度值
            //param:void
            //return:void
            //data:2022/09/17 21:28:57
            //author:wocattree
            ///////////////////////////////
            void ProduceTemps();
        };
    }
}