import svelte from "rollup-plugin-svelte";
import commonjs from "@rollup/plugin-commonjs";
import resolve from "@rollup/plugin-node-resolve";
import { terser } from 'rollup-plugin-terser';
import css from 'rollup-plugin-css-only';
import replace from '@rollup/plugin-replace';
import dotenv from 'dotenv';
import json from '@rollup/plugin-json';




dotenv.config();
const __production__ = !process.env.ROLLUP_WATCH;


const __format__ = "umd";
const __dist_path__ = "../public/dist/";


const __home__ = "home";
const __home_bundle__ = "home-bundle";
const __about__ = "about";
const __about_bundle__ = "about-bundle";




export default [
    {
        //#region /
        input: "src/home.js",
        output: {
            sourcemap: true,
            format: __format__,
            name: __home__,
            file: __dist_path__ + __home_bundle__ + '.js'
        },
        plugins: [,
            replace({
                envIS_DEBUG: JSON.stringify(process.env.envIS_DEBUG),
                envBASE_DOMAIN: JSON.stringify(process.env.envBASE_DOMAIN),
                envPROJECT_NAME: JSON.stringify(process.env.envPROJECT_NAME),
            }),
            svelte({
                compilerOptions: {
                    dev: !__production__
                }
            }),
            css({
                output: __home_bundle__ + '.css'
            }),
            resolve({
                browser: true,
                dedupe: ['svelte']
            }),
            json(),
            commonjs(),
            __production__ && terser()
        ]
        //#endregion
    },
    {
        //#region /about
        input: "src/about.js",
        output: {
            sourcemap: true,
            format: __format__,
            name: __about__,
            file: __dist_path__ + __about_bundle__ + '.js'
        },
        plugins: [,
            replace({
                envIS_DEBUG: JSON.stringify(process.env.envIS_DEBUG),
                envBASE_DOMAIN: JSON.stringify(process.env.envBASE_DOMAIN),
                envPROJECT_NAME: JSON.stringify(process.env.envPROJECT_NAME),
            }),
            svelte({
                compilerOptions: {
                    dev: !__production__
                }
            }),
            css({
                output: __about_bundle__ + '.css'
            }),
            resolve({
                browser: true,
                dedupe: ['svelte']
            }),
            json(),
            commonjs(),
            __production__ && terser()
        ]
        //#endregion
    }
];
