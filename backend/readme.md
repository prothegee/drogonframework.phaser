# `drogonframework-phaser backend`

__note:__
```
drogonframework-phaser backend resource
```

<br>

---

## helper / something hidden

- cmake settings on `./.vscode/settings.json`:
```json
<!-- linux -->
{
    "cmake.generator": "Ninja",
    "cmake.configureSettings":
    {
        "CMAKE_TOOLCHAIN_FILE": "~/vcpkg/scripts/buildsystems/vcpkg.cmake",
        "CMAKE_CXX_FLAGS": "-std=c++20 -fcoroutines",
        "cmake.buildDirectory": "${workspaceFolder}/build",
    }
}
<!-- windows -->
{
    "cmake.generator": "Ninja",
    "cmake.configureSettings":
    {
        "CMAKE_TOOLCHAIN_FILE": "~/vcpkg/scripts/buildsystems/vcpkg.cmake",
        "CMAKE_CXX_FLAGS": "/std:c++20",
        "cmake.buildDirectory": "${workspaceFolder}/build",
    }
}
```

<br>

- config on `./config.json`
```json
{
    "custom_config": {
        "envIS_DEBUG": true,
        "envBASE_DOMAIN": "127.0.0.1:8080",
        "envPROJECT_NAME": "drogonframework-phaser"
    },
    "listeners": [
        {
            "address": "0.0.0.0",
            "port": 8080,
            "https": false
        }
    ],
    "mime": {
        "text/markdown": "md",
        "text/gemini": ["gmi", "gemini"],
        "text/css": ["css", "css.map"],
        "text/javascript": ["js", "mjs", "js.map", "framework.js", "loader.js", "data", "wasm"]
    },
    // // turn this on if available
    // "db_clients": [
    //     {
    //         "rdbms": "postgresql",
    //         "host": "localhost",
    //         "port": 5432,
    //         "dbname": "dbname", // DOUBLE CHECK
    //         "user": "dbuser", // DOUBLE CHECK
    //         "passwd": "dbpwd123", // DOUBLE CHECK
    //         "is_fast": false,
    //         "timeout": -1.0
    //     }
    // ]
    "app": {
        "number_of_threads": 2, // DOUBLE CHECK
        "document_root": "../../public",
        "enable_session": true,
        "session_timeout": 518400, // seconds
        // valid value is either 'Null' (default), 'Lax', 'Strict' or 'None'
        "session_same_site" : "Lax",
        // max_connections: maximum connections number, 100000 by default
        "max_connections": 100000,
        // max_connections_per_ip: maximum connections number per clinet,0 by default which means no limit
        "max_connections_per_ip": 0,
        "log": {
            "log_path": "../logs/trace",
            "logfile_base_name": "drogonframework-phaser-trace",
            "log_size_limit": 100000000,
            "log_level": "TRACE"
        },
        "run_as_daemon": false, // DOUBLE CHECK
        "relaunch_on_error": false, // DOUBLE CHECK
        "upload_path": "media",
        "use_sendfile": true,
        "use_gzip": true,
        "use_brotli": true,
        "static_files_cache_time": 6, // in second
        "idle_connection_timeout": 12,
        "enable_server_header": true,
        "server_header_field": "drogonframework",
        "enable_date_header": true,
        // // static_file_headers: Headers for static files
        // "static_file_headers": [
        //     {
        //         "name": "Strict-Transport-Security",
        //         "value": "max-age=518400"
        //     }
        // ],
        "keepalive_requests": 0,
        "br_static": true,
        "file_types": [
            "gif",
            "png",
            "jpg",
            "map",
            "js",
            "framework.js",
            "loader.js",
            "bundle.js",
            "min.js",
            "js.map",
            "js.flow",
            "module.js",
            "cjs",
            "mjs",
            "css",
            "css.map",
            "min.css",
            "min.css.map",
            "rtl.css.map",
            "rtl.min.css.map",
            "scss",
            "html",
            "ico",
            "swf",
            "svg",
            "xap",
            "apk",
            "cur",
            "xml",
            "woff",
            "woff2",
            "text",
            "txt",
            "json",
            "data",
            "wasm"
        ]
    },
    "plugins": [
        {
            "name": "drogon::plugin::AccessLogger",
            "dependencies": [],
            "config": {
                "log_path": "../logs/access",
                "log_format": "$request_date $method $url [$body_bytes_received] ($remote_addr - $local_addr) $status $body_bytes_sent $processing_time",
                "log_file": "drogonframework-phaser-access.log",
                "log_size_limit": 100000000,
                "use_local_time": true,
                "log_index": 0
            }
        },
        {
            "name": "CInitialize",
            "dependencies": [],
            "config":
            {

            }
        }
    ]
}
```

<br>

- standalone config on `./config.json`
```json
{
    "custom_config": {
        "envIS_DEBUG": true,
        "envBASE_DOMAIN": "127.0.0.1:8080",
        "envPROJECT_NAME": "drogonframework-phaser"
    },
    "ssl": {
        "cert": "../../<path>/<to>/<your>/<cert>/TBD.pem",
        "key": "../../<path>/<to>/<your>/<cert>/TBD.pem",
        "use_old_tls": false,
        "conf": [
            ["MinProtocol", "TLSv1.2"],
            ["MaxProtocol", "TLSv1.2"],
            ["-min_protocol ", "TLSv1.2"],
            ["-max_protocol ", "TLSv1.3"],
            ["Options", "-strict, -SessionTicket, Compression"],
            ["Curves", "P-256:P-384"],
            ["SignatureAlgorithms", "CDSA+SHA256:RSA+SHA256:DSA+SHA256"],
            ["-dhparam", "../../<path>/<to>/<your>/<dhparam>/domain_dhparam.pem"],
            ["DHParameters", "../../<path>/<to>/<your>/<dhparam>/domain_dhparam.pem"],
            ["-cipher", "ECDHE-ECDSA-AES128-GCM-SHA256:ECDHE-RSA-AES128-GCM-SHA256:ECDHE-ECDSA-AES256-GCM-SHA384:ECDHE-RSA-AES256-GCM-SHA384:ECDHE-ECDSA-CHACHA20-POLY1305:ECDHE-RSA-CHACHA20-POLY1305:DHE-RSA-AES128-GCM-SHA256:DHE-RSA-AES256-GCM-SHA384"],
            ["CipherString", "ECDHE-ECDSA-AES128-GCM-SHA256:ECDHE-RSA-AES128-GCM-SHA256:ECDHE-ECDSA-AES256-GCM-SHA384:ECDHE-RSA-AES256-GCM-SHA384:ECDHE-ECDSA-CHACHA20-POLY1305:ECDHE-RSA-CHACHA20-POLY1305:DHE-RSA-AES128-GCM-SHA256:DHE-RSA-AES256-GCM-SHA384"],
            ["ChainCAFile", "../../<path>/<to>/<your>/<cert>/AAACertificateServices.crt"],
            ["VerifyCAFile", "../../<path>/<to>/<your>/<cert>/AAACertificateServices.crt"],
            ["RequestCAFile", "../../<path>/<to>/<your>/<cert>/AAACertificateServices.crt"],
            ["-serverpref", "off"],
            ["ServerPreference", "off"],
            ["-no_ticket", "off"],
            ["-SessionTicket", "off"]
        ]
    },
    "listeners": [
        {
            "address": "0.0.0.0",
            "port": 80,
            "https": true,
            "cert": "../../<path>/<to>/<your>/<cert>/TBD.pem",
            "key": "../../<path>/<to>/<your>/<cert>/TBD.pem"
        },
        {
            "address": "0.0.0.0",
            "port": 443,
            "https": true,
            "cert": "../../<path>/<to>/<your>/<cert>/TBD.pem",
            "key": "../../<path>/<to>/<your>/<cert>/TBD.pem"
        },
    ],
    "mime": {
        "text/markdown": "md",
        "text/gemini": ["gmi", "gemini"],
        "text/css": ["css", "css.map"],
        "text/javascript": ["js", "mjs", "js.map", "framework.js", "loader.js", "data", "wasm"]
    },
    // // turn this on if available
    // "db_clients": [
    //     {
    //         "rdbms": "postgresql",
    //         "host": "localhost",
    //         "port": 5432,
    //         "dbname": "dbname", // DOUBLE CHECK
    //         "user": "dbuser", // DOUBLE CHECK
    //         "passwd": "dbpwd123", // DOUBLE CHECK
    //         "is_fast": false,
    //         "timeout": -1.0
    //     }
    // ]
    "app": {
        "number_of_threads": 2, // DOUBLE CHECK
        "document_root": "../../public",
        "enable_session": true,
        "session_timeout": 518400, // seconds
        // valid value is either 'Null' (default), 'Lax', 'Strict' or 'None'
        "session_same_site" : "Lax",
        // max_connections: maximum connections number, 100000 by default
        "max_connections": 100000,
        // max_connections_per_ip: maximum connections number per clinet,0 by default which means no limit
        "max_connections_per_ip": 0,
        "log": {
            "log_path": "../logs/trace",
            "logfile_base_name": "drogonframework-phaser-trace",
            "log_size_limit": 100000000,
            "log_level": "TRACE"
        },
        "run_as_daemon": false, // DOUBLE CHECK
        "relaunch_on_error": false, // DOUBLE CHECK
        "upload_path": "media",
        "use_sendfile": true,
        "use_gzip": true,
        "use_brotli": true,
        "static_files_cache_time": 6, // in second
        "idle_connection_timeout": 12,
        "enable_server_header": true,
        "server_header_field": "drogonframework",
        "enable_date_header": true,
        // // static_file_headers: Headers for static files
        // "static_file_headers": [
        //     {
        //         "name": "Strict-Transport-Security",
        //         "value": "max-age=518400"
        //     }
        // ],
        "keepalive_requests": 0,
        "br_static": true,
        "file_types": [
            "gif",
            "png",
            "jpg",
            "map",
            "js",
            "framework.js",
            "loader.js",
            "bundle.js",
            "min.js",
            "js.map",
            "js.flow",
            "module.js",
            "cjs",
            "mjs",
            "css",
            "css.map",
            "min.css",
            "min.css.map",
            "rtl.css.map",
            "rtl.min.css.map",
            "scss",
            "html",
            "ico",
            "swf",
            "svg",
            "xap",
            "apk",
            "cur",
            "xml",
            "woff",
            "woff2",
            "text",
            "txt",
            "json",
            "data",
            "wasm"
        ]
    },
    "plugins": [
        {
            "name": "drogon::plugin::AccessLogger",
            "dependencies": [],
            "config": {
                "log_path": "../logs/access",
                "log_format": "$request_date $method $url [$body_bytes_received] ($remote_addr - $local_addr) $status $body_bytes_sent $processing_time",
                "log_file": "drogonframework-phaser-access.log",
                "log_size_limit": 100000000,
                "use_local_time": true,
                "log_index": 0
            }
        },
        {
            "name": "CInitialize",
            "dependencies": [],
            "config":
            {

            }
        }
    ]
}
```

<br>

---

###### end of drogonframework-phaser backend
