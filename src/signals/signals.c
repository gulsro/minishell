#include "../../include/minishell.h"

struct sigaction {
    void   (*sa_handler)(int);    /* Address of handler */
    sigset_t sa_mask;             /* Signals blocked during handler
                                     invocation */
    int      sa_flags;            /* Flags controlling handler invocation */
    void   (*sa_restorer)(void);  /* Not for application use */
};

struct sigaction sa;


void signal_handler(t_tools *tools, int signal_type)
{
	if (tools->interactive == 1)
	{
		if (signal_type == SIGINT)
		{
			signal_flag = 1;
		}
	}
}
interactivemod

//non interactive -- heredoc related, while reading a script



int init_signal(t_tools *tools)
{
	struct sigaction sa;

	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
    if signal == SIGINT
    {
        signal_handler(tools, SIGINT);
        sigaction.sa_flags = 1;
    }
    else if signal == SIGTERM
        signal_handler(SIGTERM)
}
//this returns global flag for the case "signal received??"
//if necessary it exits the prgoram, or get the prompt back??

