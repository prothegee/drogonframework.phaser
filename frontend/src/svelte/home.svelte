<script>
    import Phaser from "phaser";


    import CTestCase from "../js/CTestCase.js";


    // test data name member from Test Case class
    const TestCase = new CTestCase();




    var config = {
        type: Phaser.AUTO,
        width: 800,
        height: 600,
        physics: {
            default: "arcade",
            arcade: {
                gravity: {
                    y: 200
                }
            }
        },
        scene: {
            preload: preload,
            create: create
        }
    };


    var game = new Phaser.Game(config);


    function preload()
    {
        this.load.setBaseURL(envBASE_DOMAIN);

        this.load.image("sky", "/assets/game/home/space3.png");
        this.load.image("logo", "/assets/game/home/phaser3-logo.png");
        this.load.image("red", "/assets/game/home/red.png");
    }


    function create()
    {
        this.add.image(400, 300, 'sky');

        var particles = this.add.particles('red');

        var emitter = particles.createEmitter({
            speed: 100,
            scale: { start: 1, end: 0 },
            blendMode: 'ADD'
        });

        var logo = this.physics.add.image(400, 100, 'logo');

        logo.setVelocity(100, 200);
        logo.setBounce(1, 1);
        logo.setCollideWorldBounds(true);

        emitter.startFollow(logo);
    }


    console.log(`-- TestCase name: ${TestCase.m_name}`);
</script>




<main>
    <!-- svelte-ignore missing-declaration -->
    <h3>{envPROJECT_NAME} | HOME</h3>
</main>




<style>
    /*  */
</style>
