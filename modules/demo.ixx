// =============================================
// Primary Module Interface Unit
// =============================================
// This is the main entry point for the Demo module.
// It imports and re-exports all module partitions, making
// their symbols available to consumers who do 'import Demo;'
// =============================================

module;
export module Demo;

// Import and re-export all module partitions
export import :interface_partition_non_template;  // non-template functions
export import :interface_partition_template;      // template functions