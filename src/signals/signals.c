#include "../../include/minishell.h"

struct sigaction {
    void   (*sa_handler)(int);    /* Address of handler */
    sigset_t sa_mask;             /* Signals blocked during handler
                                     invocation */
    int      sa_flags;            /* Flags controlling handler invocation */
    void   (*sa_restorer)(void);  /* Not for application use */
};

struct sigaction sa;


int init_signal()
{
    if signal == SIGINT
    {
        signal_handler(SIGINT)
        sigaction.sa_flags = 
    }
    else if signal == SIGTERM
        signal_handler(SIGTERM)
}
//this returns global flag for the case "signal received??"
//if necessary it exits the prgoram, or get the prompt back??

void signal_handler(signum int)
interactivemod

//non interactive -- heredoc related, while reading a script


