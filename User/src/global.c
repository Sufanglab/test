#include "global.h"
//李厚霖注释，2.16
//这里相当于一个基类，可以在其他地方直接调用，实现共同的功能

void BaseModule_Init(baseModule *base) {   //初始化，STATE设置成READY，同时把错误清零
    base->state = MODULE_READY;
    base->error_code = 0;
}

void BaseModule_Stop(baseModule *base) {   //停止
    base->state = MODULE_READY;
}

void BaseModule_Run(baseModule *base) {    //运行
    base->state = MODULE_RUNNING;
}
ModuleState BaseModule_GetState(baseModule *base) {    //获取状态，直接输出STATE
    return base->state;
}

void BaseModule_ClearError(baseModule *base) {        //把错误清零
    base->error_code = 0;
    base->state = MODULE_READY;
}
