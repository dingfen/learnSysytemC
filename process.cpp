#include <systemc>

using namespace sc_core;

SC_MODULE(PROCESS) {
    sc_clock clk;
    SC_CTOR(PROCESS) : clk("clk", 1, SC_SEC) {
        SC_METHOD(method);
        SC_THREAD(thread);
        SC_CTHREAD(cthread, clk);
    }

    void method() {
        std::cout << "method triggered @ " << sc_time_stamp() << std::endl;
        next_trigger(sc_time(1, SC_SEC));
    }

    void thread() {
        while (1) {
            std::cout << "thread triggered @ " << sc_time_stamp() << std::endl;
            wait(1, SC_SEC);
        }
    }

    void cthread() {
        while (1) {
            std::cout << "cthread triggered @ " << sc_time_stamp() << std::endl;
            wait();
        }
    }
};


int sc_main(int, char**) {
    PROCESS module_a("module_a");
    sc_start(4, SC_SEC);

    return 0;
}