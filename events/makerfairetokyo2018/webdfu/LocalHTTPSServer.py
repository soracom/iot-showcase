#!/usr/bin/python

# python3 LocalHTTPSServer.py

from http.server import HTTPServer, SimpleHTTPRequestHandler
import ssl
    
def run(args):
    server = HTTPServer((args.hostname, args.port), SimpleHTTPRequestHandler)
    server.socket = ssl.wrap_socket(server.socket, certfile=args.cert, server_side=True)
    name, addr = server.socket.getsockname()
    print("Serving HTTPS on {} port {}...".format(name, addr))
    try:
        server.serve_forever()
    except KeyboardInterrupt:
        pass
    server.server_close()
    print('Server Stops - %s:%s' % (name, addr))

if __name__ == '__main__':
    import argparse
    parser = argparse.ArgumentParser()
    parser.add_argument("--hostname", default="localhost")
    parser.add_argument("--port", type=int, default=8443)
    parser.add_argument("--cert", default="LocalHTTPSServer.pem")

    args = parser.parse_args()
    
    run(args)
