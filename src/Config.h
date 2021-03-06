#ifndef __NNDEP_CONFIG_H__
#define __NNDEP_CONFIG_H__

#include <string>
#include <map>

class Config
{
    public:
        static const std::string UNKNOWN;
        static const std::string ROOT;
        static const int UNKNOWN_INT;

        static const int BASIC_FEAT = 0;
        static const int DIST_FEAT = 1;
        static const int VALENCY_FEAT = 2;
        static const int CLUSTER_FEAT = 3;
        static const int CONST_FEAT = 4;
        static const int LENGTH_FEAT = 5;

        /**
         * for printing message
         */
        static const std::string SEPERATOR;
        static const std::string NIL;   // non-exist
        static const int NONEXIST;      // head of ROOT

        int training_threads;
        int word_cut_off;

        /**
         * model weights initialization range
         */
        double init_range;

        int max_iter;

        int finetune_iter;

        int batch_size;

        /**
         * hyper-parameters for AdaGrad
         */
        double ada_eps;
        double ada_alpha;
        double reg_parameter;

        double dropout_prob;

        int hidden_size;
        int embedding_size;

        // for multi-task learning
        int phidden_size; // private hidden size

        /**
         * number of tokens as input to the neural net
         */
        int num_tokens;

        int num_const_tokens; // 0|18

        int num_basic_tokens;
        int num_word_tokens; // 18
        int num_pos_tokens;  // 18
        int num_label_tokens;// 12

        int num_dist_tokens; // 1
        int num_valency_tokens; // 3
        int num_cluster_tokens; // 14
        int num_length_tokens; // 1

        int num_pre_computed;

        int eval_per_iter;

        /**
         * clear adagrad gradient histories after every iteration
         * (confused)
         * if zero, never clear gradients
         */
        int clear_gradient_per_iter;

        std::string oracle_file;
        bool print_oracle;
        /**
         * save model whenver we see an improved UAS evaluation
         */
        bool save_intermediate;

        /**
         * whether fix embeddings
         */
        bool fix_word_embeddings;

        /**
         * whether use word features
         */
        bool delexicalized;

        /**
         * whether use const look-up table
         */
        bool use_pretrained;

        /**
         * oracle
         */
        std::string oracle;

        /**
         * labeled or unlabeled
         */
        bool labeled;

        /**
         * whether use distance feature
         */
        bool use_distance;
        int distance_embedding_size; // unused

        /**
         * whether use valency feature
         */
        bool use_valency;
        int valency_embedding_size;

        /**
         * whether use cluster feature
         */
        bool use_cluster;
        int cluster_embedding_size;

        /**
         * whether use pass buffer size feature
         */
        bool use_length;
        int length_embedding_size;

        /**
         * whether use postag feature
         */
        bool use_postag;

        std::string language;

        /**
         * compositional embedding size
         */
        int num_compose_tokens;
        int compose_embedding_size;

        bool compose_weighted;
        bool compose_by_position;
        int max_compose_layers;

        int compose_activation;

        bool debug;

    public:
        Config();
        Config(const char * filename);
        Config(const std::string& filename);
        ~Config() {};

        void init();
        void set_properties(const char * filename);
        void print_info();

        int get_embedding_size(int i);
        int get_feat_type(int i);
        int get_offset(int pos);

    private:
        void cfg_set_int(
                std::map<std::string, std::string>& props,
                const char * name,
                int& variable);

        void cfg_set_double(
                std::map<std::string, std::string>& props,
                const char * name,
                double& variable);

        void cfg_set_boolean(
                std::map<std::string, std::string>& props,
                const char * name,
                bool& variable);
};

#endif
