////////////////////////////////
//filename:SimuTempModule.h
//description:ģ���¶Ȳ���ģ��
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
            //description:��������¶�ֵ����
            //param:
            //return:
            //data:2022/09/17 21:29:38
            //author:wocattree
            ///////////////////////////////
            std::vector<float> GetSimuTemoInfos();

        /*    int Run();*/

        private:
            std::vector<float>                vSimuTempInfos;            //ģ��������¶���ֵ�б�
            int                               TempIndex;                         //�¶�ֵ��������
        
        private:
            ////////////////////////////////
            //funcname:ProduceTemps
            //description:��������¶�ֵ
            //param:void
            //return:void
            //data:2022/09/17 21:28:57
            //author:wocattree
            ///////////////////////////////
            void ProduceTemps();
        };
    }
}