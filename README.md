# NetImgui extension for Defold

[NetImgui](https://github.com/sammyfreg/netImgui) is a library for remotely displaying and controlling Dear Imgui content in a different application (called the Server).

This extension works alongside [extension-imgui](https://github.com/britzl/extension-imgui) to make remoting available to Defold applications.

## Usage
1. Add extension-imgui and extension-netimgui to your application
2. Use imgui in the normal way - see extension-imgui documentation for more details
3. Adding netimgui/netimgui.script will handle input, and also disables local imgui rendering when a Server is connected.

## Server application
To connect to your Defold application running this extension, you'll need the NetImgui server application. The NetImgui distribution includes instructions for building on Windows, but the code is quite portable and can be built for MacOS.

There are two options for establishing the connection, and [example/example.script](/example/example.script) covers both:
1. Connect from your Defold app to the server app by calling netimgui.connect_to_app() and specifying a host name or IP address.
2. Instruct your Defold app to allow incoming connections by calling netimgui.connect_from_app()

The second option is typically best, as it means that your app/game runs as normal, but will automatically connect to a server.
