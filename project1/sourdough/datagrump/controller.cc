#include <iostream>

#include "controller.hh"
#include "timestamp.hh"

using namespace std;

/* Default constructor */
Controller::Controller( const bool debug )
  : debug_( debug )//, size(4), min(45), seq(1), slow_start(true)
{}

/* Get current window size, in datagrams */
unsigned int Controller::window_size()
{
  //42 or 45
  
  /*
  unsigned int the_window_size = size;
  if ( debug_ ) {
    cerr << "At time " << timestamp_ms()
	 << " window size is " << the_window_size << endl;
  }
*/
  return 45;
}

/* A datagram was sent */
void Controller::datagram_was_sent( const uint64_t sequence_number,
				    /* of the sent datagram */
				    const uint64_t send_timestamp,
                                    /* in milliseconds */
				    const bool after_timeout
				    /* datagram was sent because of a timeout */ )
{
  /* Default: take no action 
  if(after_timeout){
    size /=2;
    slow_start = false;
  }
  */
  if ( debug_ ) {
    cerr << "At time " << send_timestamp
	 << " sent datagram " << sequence_number << " (timeout = " << after_timeout << ")\n";
  }
}

/* An ack was received */
void Controller::ack_received( const uint64_t sequence_number_acked,
			       /* what sequence number was acknowledged */
			       const uint64_t send_timestamp_acked,
			       /* when the acknowledged datagram was sent (sender's clock) */
			       const uint64_t recv_timestamp_acked,
			       /* when the acknowledged datagram was received (receiver's clock)*/
			       const uint64_t timestamp_ack_received )
                               /* when the ack was received (by sender) */
{
  /* Default: take no action 
    int n = recv_timestamp_acked - send_timestamp_acked; 
    int m = timestamp_ack_received - recv_timestamp_acked;
    uint64_t max_acked_seq = max(max_acked_seq, sequence_number_acked);
    bool b = (max_acked_seq == sequence_number_acked);
    
    
  if (b and m <130 and n < 1)
  {
    size = size+1;
  
  }

  if(b and m <130 and size > 48 and n > 1)
  {
    size = size-2 ;
  }
  
*/
 
  /*
  
  
*/

  if ( debug_ ) {
    cerr << "At time " << timestamp_ack_received
	 << " received ack for datagram " << sequence_number_acked
	 << " (send @ time " << send_timestamp_acked
	 << ", received @ time " << recv_timestamp_acked << " by receiver's clock)"
	 << endl;
  }
}

/* How long to wait (in milliseconds) if there are no acks
   before sending one more datagram */
unsigned int Controller::timeout_ms()
{
  return 1000; /* timeout of one second */
}
