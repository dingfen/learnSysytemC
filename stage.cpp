#include <systemc>

using namespace sc_core;

SC_MODULE(STAGE) {
    SC_CTOR(STAGE) {
        std::cout << sc_time_stamp() << ": Elaboration: constructor" << std::endl;
        SC_THREAD(thread);
    }

    ~STAGE() {
        std::cout << sc_time_stamp() << ": Cleanup: desctructor" << std::endl;
    }

    void thread() {
        std::cout << sc_time_stamp() << ": Execution.initialization" << std::endl;
        int i = 0;
        while (1) {
            wait(1, SC_SEC);
            std::cout << sc_time_stamp() << ": Execution.simulation" << std::endl;
            if (++i >= 2) {
              sc_stop();
            }
        }
    }

    void before_end_of_elaboration() {
        std::cout << "before end of elaboration" << std::endl;
    }

    void end_of_elaboration() {
        std::cout << "end of elaboration" << std::endl;
    }
    void start_of_simulation() {
        std::cout << "start of simulation" << std::endl;
    }
    void end_of_simulation() {
        std::cout << "end of simulation" << std::endl;
    }
};


int sc_main(int, char **) {
    STAGE s("stage");
    sc_start();
    return 0;
}