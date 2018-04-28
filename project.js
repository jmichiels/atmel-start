ACME.Start.openProject("format_version: '2'\nname: My Project\nboard:\n  identifier: CustomBoard\n  device: SAMD21G18A-MF\ndetails: null\napplication: null\nmiddlewares: {}\ndrivers:\n  GCLK:\n    user_label: GCLK\n    definition: Atmel:SAMD21_Drivers:0.0.1::SAMD21G18A-MF::GCLK::driver_config_definition::GCLK::HAL:HPL:GCLK\n    functionality: System\n    api: HAL:HPL:GCLK\n    configuration:\n      enable_gclk_gen_0: true\n      enable_gclk_gen_1: false\n      enable_gclk_gen_2: false\n      enable_gclk_gen_3: false\n      enable_gclk_gen_4: false\n      enable_gclk_gen_5: false\n      enable_gclk_gen_6: false\n      enable_gclk_gen_7: false\n      gclk_arch_gen_0_RUNSTDBY: false\n      gclk_arch_gen_0_enable: true\n      gclk_arch_gen_0_idc: false\n      gclk_arch_gen_0_oe: false\n      gclk_arch_gen_0_oov: false\n      gclk_arch_gen_1_RUNSTDBY: false\n      gclk_arch_gen_1_enable: false\n      gclk_arch_gen_1_idc: false\n      gclk_arch_gen_1_oe: false\n      gclk_arch_gen_1_oov: false\n      gclk_arch_gen_2_RUNSTDBY: false\n      gclk_arch_gen_2_enable: false\n      gclk_arch_gen_2_idc: false\n      gclk_arch_gen_2_oe: false\n      gclk_arch_gen_2_oov: false\n      gclk_arch_gen_3_RUNSTDBY: false\n      gclk_arch_gen_3_enable: false\n      gclk_arch_gen_3_idc: false\n      gclk_arch_gen_3_oe: false\n      gclk_arch_gen_3_oov: false\n      gclk_arch_gen_4_RUNSTDBY: false\n      gclk_arch_gen_4_enable: false\n      gclk_arch_gen_4_idc: false\n      gclk_arch_gen_4_oe: false\n      gclk_arch_gen_4_oov: false\n      gclk_arch_gen_5_RUNSTDBY: false\n      gclk_arch_gen_5_enable: false\n      gclk_arch_gen_5_idc: false\n      gclk_arch_gen_5_oe: false\n      gclk_arch_gen_5_oov: false\n      gclk_arch_gen_6_RUNSTDBY: false\n      gclk_arch_gen_6_enable: false\n      gclk_arch_gen_6_idc: false\n      gclk_arch_gen_6_oe: false\n      gclk_arch_gen_6_oov: false\n      gclk_arch_gen_7_RUNSTDBY: false\n      gclk_arch_gen_7_enable: false\n      gclk_arch_gen_7_idc: false\n      gclk_arch_gen_7_oe: false\n      gclk_arch_gen_7_oov: false\n      gclk_gen_0_div: 1\n      gclk_gen_0_div_sel: false\n      gclk_gen_0_oscillator: 8MHz Internal Oscillator (OSC8M)\n      gclk_gen_1_div: 1\n      gclk_gen_1_div_sel: false\n      gclk_gen_1_oscillator: External Crystal Oscillator 0.4-32MHz (XOSC)\n      gclk_gen_2_div: 1\n      gclk_gen_2_div_sel: false\n      gclk_gen_2_oscillator: External Crystal Oscillator 0.4-32MHz (XOSC)\n      gclk_gen_3_div: 1\n      gclk_gen_3_div_sel: false\n      gclk_gen_3_oscillator: External Crystal Oscillator 0.4-32MHz (XOSC)\n      gclk_gen_4_div: 1\n      gclk_gen_4_div_sel: false\n      gclk_gen_4_oscillator: External Crystal Oscillator 0.4-32MHz (XOSC)\n      gclk_gen_5_div: 1\n      gclk_gen_5_div_sel: false\n      gclk_gen_5_oscillator: External Crystal Oscillator 0.4-32MHz (XOSC)\n      gclk_gen_6_div: 1\n      gclk_gen_6_div_sel: false\n      gclk_gen_6_oscillator: External Crystal Oscillator 0.4-32MHz (XOSC)\n      gclk_gen_7_div: 1\n      gclk_gen_7_div_sel: false\n      gclk_gen_7_oscillator: External Crystal Oscillator 0.4-32MHz (XOSC)\n    optional_signals: []\n    variant: null\n    clocks:\n      domain_group: null\n  PM:\n    user_label: PM\n    definition: Atmel:SAMD21_Drivers:0.0.1::SAMD21G18A-MF::PM::driver_config_definition::PM::HAL:HPL:PM\n    functionality: System\n    api: HAL:HPL:PM\n    configuration:\n      apba_div: '1'\n      apbb_div: '1'\n      apbc_div: '1'\n      cpu_clock_source: Generic clock generator 0\n      cpu_div: '1'\n      enable_cpu_clock: true\n      nvm_wait_states: '0'\n    optional_signals: []\n    variant: null\n    clocks:\n      domain_group:\n        nodes:\n        - name: CPU\n          input: CPU\n        configuration: {}\n  DMAC:\n    user_label: DMAC\n    definition: Atmel:SAMD21_Drivers:0.0.1::SAMD21G18A-MF::DMAC::driver_config_definition::DMAC::HAL:HPL:DMAC\n    functionality: System\n    api: HAL:HPL:DMAC\n    configuration:\n      dmac_beatsize_0: 8-bit bus transfer\n      dmac_beatsize_1: 8-bit bus transfer\n      dmac_beatsize_10: 8-bit bus transfer\n      dmac_beatsize_11: 8-bit bus transfer\n      dmac_beatsize_12: 8-bit bus transfer\n      dmac_beatsize_13: 8-bit bus transfer\n      dmac_beatsize_14: 8-bit bus transfer\n      dmac_beatsize_15: 8-bit bus transfer\n      dmac_beatsize_2: 8-bit bus transfer\n      dmac_beatsize_3: 8-bit bus transfer\n      dmac_beatsize_4: 8-bit bus transfer\n      dmac_beatsize_5: 8-bit bus transfer\n      dmac_beatsize_6: 8-bit bus transfer\n      dmac_beatsize_7: 8-bit bus transfer\n      dmac_beatsize_8: 8-bit bus transfer\n      dmac_beatsize_9: 8-bit bus transfer\n      dmac_blockact_0: Channel will be disabled if it is the last block transfer in\n        the transaction\n      dmac_blockact_1: Channel will be disabled if it is the last block transfer in\n        the transaction\n      dmac_blockact_10: Channel will be disabled if it is the last block transfer\n        in the transaction\n      dmac_blockact_11: Channel will be disabled if it is the last block transfer\n        in the transaction\n      dmac_blockact_12: Channel will be disabled if it is the last block transfer\n        in the transaction\n      dmac_blockact_13: Channel will be disabled if it is the last block transfer\n        in the transaction\n      dmac_blockact_14: Channel will be disabled if it is the last block transfer\n        in the transaction\n      dmac_blockact_15: Channel will be disabled if it is the last block transfer\n        in the transaction\n      dmac_blockact_2: Channel will be disabled if it is the last block transfer in\n        the transaction\n      dmac_blockact_3: Channel will be disabled if it is the last block transfer in\n        the transaction\n      dmac_blockact_4: Channel will be disabled if it is the last block transfer in\n        the transaction\n      dmac_blockact_5: Channel will be disabled if it is the last block transfer in\n        the transaction\n      dmac_blockact_6: Channel will be disabled if it is the last block transfer in\n        the transaction\n      dmac_blockact_7: Channel will be disabled if it is the last block transfer in\n        the transaction\n      dmac_blockact_8: Channel will be disabled if it is the last block transfer in\n        the transaction\n      dmac_blockact_9: Channel will be disabled if it is the last block transfer in\n        the transaction\n      dmac_channel_0_settings: false\n      dmac_channel_10_settings: false\n      dmac_channel_11_settings: false\n      dmac_channel_12_settings: false\n      dmac_channel_13_settings: false\n      dmac_channel_14_settings: false\n      dmac_channel_15_settings: false\n      dmac_channel_1_settings: false\n      dmac_channel_2_settings: false\n      dmac_channel_3_settings: false\n      dmac_channel_4_settings: false\n      dmac_channel_5_settings: false\n      dmac_channel_6_settings: false\n      dmac_channel_7_settings: false\n      dmac_channel_8_settings: false\n      dmac_channel_9_settings: false\n      dmac_dbgrun: false\n      dmac_dstinc_0: false\n      dmac_dstinc_1: false\n      dmac_dstinc_10: false\n      dmac_dstinc_11: false\n      dmac_dstinc_12: false\n      dmac_dstinc_13: false\n      dmac_dstinc_14: false\n      dmac_dstinc_15: false\n      dmac_dstinc_2: false\n      dmac_dstinc_3: false\n      dmac_dstinc_4: false\n      dmac_dstinc_5: false\n      dmac_dstinc_6: false\n      dmac_dstinc_7: false\n      dmac_dstinc_8: false\n      dmac_dstinc_9: false\n      dmac_enable: false\n      dmac_enable_0: false\n      dmac_enable_1: false\n      dmac_enable_10: false\n      dmac_enable_11: false\n      dmac_enable_12: false\n      dmac_enable_13: false\n      dmac_enable_14: false\n      dmac_enable_15: false\n      dmac_enable_2: false\n      dmac_enable_3: false\n      dmac_enable_4: false\n      dmac_enable_5: false\n      dmac_enable_6: false\n      dmac_enable_7: false\n      dmac_enable_8: false\n      dmac_enable_9: false\n      dmac_evact_0: No action\n      dmac_evact_1: No action\n      dmac_evact_10: No action\n      dmac_evact_11: No action\n      dmac_evact_12: No action\n      dmac_evact_13: No action\n      dmac_evact_14: No action\n      dmac_evact_15: No action\n      dmac_evact_2: No action\n      dmac_evact_3: No action\n      dmac_evact_4: No action\n      dmac_evact_5: No action\n      dmac_evact_6: No action\n      dmac_evact_7: No action\n      dmac_evact_8: No action\n      dmac_evact_9: No action\n      dmac_evie_0: false\n      dmac_evie_1: false\n      dmac_evie_10: false\n      dmac_evie_11: false\n      dmac_evie_12: false\n      dmac_evie_13: false\n      dmac_evie_14: false\n      dmac_evie_15: false\n      dmac_evie_2: false\n      dmac_evie_3: false\n      dmac_evie_4: false\n      dmac_evie_5: false\n      dmac_evie_6: false\n      dmac_evie_7: false\n      dmac_evie_8: false\n      dmac_evie_9: false\n      dmac_evoe_0: false\n      dmac_evoe_1: false\n      dmac_evoe_10: false\n      dmac_evoe_11: false\n      dmac_evoe_12: false\n      dmac_evoe_13: false\n      dmac_evoe_14: false\n      dmac_evoe_15: false\n      dmac_evoe_2: false\n      dmac_evoe_3: false\n      dmac_evoe_4: false\n      dmac_evoe_5: false\n      dmac_evoe_6: false\n      dmac_evoe_7: false\n      dmac_evoe_8: false\n      dmac_evoe_9: false\n      dmac_evosel_0: Event generation disabled\n      dmac_evosel_1: Event generation disabled\n      dmac_evosel_10: Event generation disabled\n      dmac_evosel_11: Event generation disabled\n      dmac_evosel_12: Event generation disabled\n      dmac_evosel_13: Event generation disabled\n      dmac_evosel_14: Event generation disabled\n      dmac_evosel_15: Event generation disabled\n      dmac_evosel_2: Event generation disabled\n      dmac_evosel_3: Event generation disabled\n      dmac_evosel_4: Event generation disabled\n      dmac_evosel_5: Event generation disabled\n      dmac_evosel_6: Event generation disabled\n      dmac_evosel_7: Event generation disabled\n      dmac_evosel_8: Event generation disabled\n      dmac_evosel_9: Event generation disabled\n      dmac_lvl_0: Channel priority 0\n      dmac_lvl_1: Channel priority 0\n      dmac_lvl_10: Channel priority 0\n      dmac_lvl_11: Channel priority 0\n      dmac_lvl_12: Channel priority 0\n      dmac_lvl_13: Channel priority 0\n      dmac_lvl_14: Channel priority 0\n      dmac_lvl_15: Channel priority 0\n      dmac_lvl_2: Channel priority 0\n      dmac_lvl_3: Channel priority 0\n      dmac_lvl_4: Channel priority 0\n      dmac_lvl_5: Channel priority 0\n      dmac_lvl_6: Channel priority 0\n      dmac_lvl_7: Channel priority 0\n      dmac_lvl_8: Channel priority 0\n      dmac_lvl_9: Channel priority 0\n      dmac_lvlen0: false\n      dmac_lvlen1: false\n      dmac_lvlen2: false\n      dmac_lvlen3: false\n      dmac_lvlpri0: 0\n      dmac_lvlpri1: 0\n      dmac_lvlpri2: 0\n      dmac_lvlpri3: 0\n      dmac_rrlvlen0: Static arbitration scheme for channel with priority 0\n      dmac_rrlvlen1: Static arbitration scheme for channel with priority 1\n      dmac_rrlvlen2: Static arbitration scheme for channel with priority 2\n      dmac_rrlvlen3: Static arbitration scheme for channel with priority 3\n      dmac_srcinc_0: false\n      dmac_srcinc_1: false\n      dmac_srcinc_10: false\n      dmac_srcinc_11: false\n      dmac_srcinc_12: false\n      dmac_srcinc_13: false\n      dmac_srcinc_14: false\n      dmac_srcinc_15: false\n      dmac_srcinc_2: false\n      dmac_srcinc_3: false\n      dmac_srcinc_4: false\n      dmac_srcinc_5: false\n      dmac_srcinc_6: false\n      dmac_srcinc_7: false\n      dmac_srcinc_8: false\n      dmac_srcinc_9: false\n      dmac_stepsel_0: Step size settings apply to the destination address\n      dmac_stepsel_1: Step size settings apply to the destination address\n      dmac_stepsel_10: Step size settings apply to the destination address\n      dmac_stepsel_11: Step size settings apply to the destination address\n      dmac_stepsel_12: Step size settings apply to the destination address\n      dmac_stepsel_13: Step size settings apply to the destination address\n      dmac_stepsel_14: Step size settings apply to the destination address\n      dmac_stepsel_15: Step size settings apply to the destination address\n      dmac_stepsel_2: Step size settings apply to the destination address\n      dmac_stepsel_3: Step size settings apply to the destination address\n      dmac_stepsel_4: Step size settings apply to the destination address\n      dmac_stepsel_5: Step size settings apply to the destination address\n      dmac_stepsel_6: Step size settings apply to the destination address\n      dmac_stepsel_7: Step size settings apply to the destination address\n      dmac_stepsel_8: Step size settings apply to the destination address\n      dmac_stepsel_9: Step size settings apply to the destination address\n      dmac_stepsize_0: Next ADDR = ADDR + (BEATSIZE + 1) * 1\n      dmac_stepsize_1: Next ADDR = ADDR + (BEATSIZE + 1) * 1\n      dmac_stepsize_10: Next ADDR = ADDR + (BEATSIZE + 1) * 1\n      dmac_stepsize_11: Next ADDR = ADDR + (BEATSIZE + 1) * 1\n      dmac_stepsize_12: Next ADDR = ADDR + (BEATSIZE + 1) * 1\n      dmac_stepsize_13: Next ADDR = ADDR + (BEATSIZE + 1) * 1\n      dmac_stepsize_14: Next ADDR = ADDR + (BEATSIZE + 1) * 1\n      dmac_stepsize_15: Next ADDR = ADDR + (BEATSIZE + 1) * 1\n      dmac_stepsize_2: Next ADDR = ADDR + (BEATSIZE + 1) * 1\n      dmac_stepsize_3: Next ADDR = ADDR + (BEATSIZE + 1) * 1\n      dmac_stepsize_4: Next ADDR = ADDR + (BEATSIZE + 1) * 1\n      dmac_stepsize_5: Next ADDR = ADDR + (BEATSIZE + 1) * 1\n      dmac_stepsize_6: Next ADDR = ADDR + (BEATSIZE + 1) * 1\n      dmac_stepsize_7: Next ADDR = ADDR + (BEATSIZE + 1) * 1\n      dmac_stepsize_8: Next ADDR = ADDR + (BEATSIZE + 1) * 1\n      dmac_stepsize_9: Next ADDR = ADDR + (BEATSIZE + 1) * 1\n      dmac_trifsrc_0: Only software/event triggers\n      dmac_trifsrc_1: Only software/event triggers\n      dmac_trifsrc_10: Only software/event triggers\n      dmac_trifsrc_11: Only software/event triggers\n      dmac_trifsrc_12: Only software/event triggers\n      dmac_trifsrc_13: Only software/event triggers\n      dmac_trifsrc_14: Only software/event triggers\n      dmac_trifsrc_15: Only software/event triggers\n      dmac_trifsrc_2: Only software/event triggers\n      dmac_trifsrc_3: Only software/event triggers\n      dmac_trifsrc_4: Only software/event triggers\n      dmac_trifsrc_5: Only software/event triggers\n      dmac_trifsrc_6: Only software/event triggers\n      dmac_trifsrc_7: Only software/event triggers\n      dmac_trifsrc_8: Only software/event triggers\n      dmac_trifsrc_9: Only software/event triggers\n      dmac_trigact_0: One trigger required for each block transfer\n      dmac_trigact_1: One trigger required for each block transfer\n      dmac_trigact_10: One trigger required for each block transfer\n      dmac_trigact_11: One trigger required for each block transfer\n      dmac_trigact_12: One trigger required for each block transfer\n      dmac_trigact_13: One trigger required for each block transfer\n      dmac_trigact_14: One trigger required for each block transfer\n      dmac_trigact_15: One trigger required for each block transfer\n      dmac_trigact_2: One trigger required for each block transfer\n      dmac_trigact_3: One trigger required for each block transfer\n      dmac_trigact_4: One trigger required for each block transfer\n      dmac_trigact_5: One trigger required for each block transfer\n      dmac_trigact_6: One trigger required for each block transfer\n      dmac_trigact_7: One trigger required for each block transfer\n      dmac_trigact_8: One trigger required for each block transfer\n      dmac_trigact_9: One trigger required for each block transfer\n    optional_signals: []\n    variant: null\n    clocks:\n      domain_group: null\n  SYSCTRL:\n    user_label: SYSCTRL\n    definition: Atmel:SAMD21_Drivers:0.0.1::SAMD21G18A-MF::SYSCTRL::driver_config_definition::SYSCTRL::HAL:HPL:SYSCTRL\n    functionality: System\n    api: HAL:HPL:SYSCTRL\n    configuration:\n      dfll48m_arch_bplckc: false\n      dfll48m_arch_calibration: false\n      dfll48m_arch_ccdis: false\n      dfll48m_arch_coarse: 31\n      dfll48m_arch_enable: false\n      dfll48m_arch_fine: 512\n      dfll48m_arch_llaw: false\n      dfll48m_arch_ondemand: true\n      dfll48m_arch_qldis: false\n      dfll48m_arch_runstdby: false\n      dfll48m_arch_stable: false\n      dfll48m_arch_usbcrm: false\n      dfll48m_arch_waitlock: false\n      dfll48m_mode: Open Loop Mode\n      dfll48m_mul: 0\n      dfll48m_ref_clock: Generic clock generator 3\n      dfll_arch_cstep: 1\n      dfll_arch_fstep: 1\n      enable_dfll48m: false\n      enable_fdpll96m: false\n      enable_osc32k: false\n      enable_osc8m: true\n      enable_osculp32k: true\n      enable_xosc: false\n      enable_xosc32k: false\n      fdpll96m_arch_enable: false\n      fdpll96m_arch_lbypass: false\n      fdpll96m_arch_ondemand: true\n      fdpll96m_arch_runstdby: false\n      fdpll96m_clock_div: 0\n      fdpll96m_ldr: 1463\n      fdpll96m_ldrfrac: 13\n      fdpll96m_ref_clock: Generic clock generator 3\n      osc32k_arch_calib: 0\n      osc32k_arch_en1k: false\n      osc32k_arch_en32k: false\n      osc32k_arch_enable: false\n      osc32k_arch_ondemand: true\n      osc32k_arch_overwrite_calibration: false\n      osc32k_arch_runstdby: false\n      osc32k_arch_startup: 3 Clock Cycles (92us)\n      osc32k_arch_wrtlock: false\n      osc8m_arch_calib: 0\n      osc8m_arch_enable: true\n      osc8m_arch_ondemand: true\n      osc8m_arch_overwrite_calibration: false\n      osc8m_arch_runstdby: false\n      osc8m_presc: '8'\n      osculp32k_arch_calib: 0\n      osculp32k_arch_overwrite_calibration: false\n      osculp32k_arch_wrtlock: false\n      xosc32k_arch_aampen: false\n      xosc32k_arch_en1k: false\n      xosc32k_arch_en32k: false\n      xosc32k_arch_enable: false\n      xosc32k_arch_ondemand: true\n      xosc32k_arch_runstdby: false\n      xosc32k_arch_startup: 122 us\n      xosc32k_arch_wrtlock: false\n      xosc32k_arch_xtalen: false\n      xosc_arch_ampgc: false\n      xosc_arch_enable: false\n      xosc_arch_gain: 2Mhz\n      xosc_arch_ondemand: true\n      xosc_arch_runstdby: false\n      xosc_arch_startup: 31 us\n      xosc_arch_xtalen: false\n      xosc_frequency: 400000\n    optional_signals: []\n    variant: null\n    clocks:\n      domain_group: null\npads:\n  LED_BUILTIN:\n    name: PA17\n    definition: Atmel:SAMD21_Drivers:0.0.1::SAMD21G18A-MF::pad::PA17\n    mode: Digital output\n    user_label: LED_BUILTIN\n    configuration: null\ntoolchain_options: []\n");