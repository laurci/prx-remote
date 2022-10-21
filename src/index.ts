import { createServer } from "http";
import { exec } from "child_process";

const port = parseInt(process.env.REMOTE_SRV_PORT ?? "3333");
const vmId = process.env.REMOTE_VM_ID ?? "100";

const server = createServer((req, res) => {
    if (req.url === "/start") {
        const cmd = `qm start ${vmId}`;
        console.log(`$ ${cmd}`);

        exec(cmd, (err, stdout, stderr) => {
            console.log(stdout);
            console.log(stderr);
        });

        res.writeHead(200, { "Content-Type": "text/plain" });
        res.end("ok.");
    }
});

server.listen(3333, "0.0.0.0", () => {
    console.log(`listening on *:${port}`);
});