#pragma once

namespace Spider {

class Server {
public:
  // Creates a socket on the provided port.
  // Check IsValid() before using.
  Server(const uint16_t &port);

  // Closes the socket if it was successfully created.
  ~Server();

  // If the socket was successfully created and bound
  const bool &IsValid() const { return m_IsValid; }

  // Polls the server for connections and requests
  void Update();
private:
  int m_FD = -1;

  bool m_IsValid = false;
};

}
